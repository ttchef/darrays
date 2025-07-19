
LIB_NAME = darray

# Compiler 
CC = gcc
CFLAGS = -Wall -Wextra -O2 -fPIC
LDFLAGS = -shared

# Folders
SRC_DIR = src 
INCLUDE_DIR = include 
BUILD_DIR = build 
OBJ_DIR = $(BUILD_DIR)/obj

# installation
PREFIX = /usr/local 
LIBDIR = $(PREFIX)/lib 
INCLUDEDIR = $(PREFIX)/include

# Source Files 
SOURCES = $(wildcard $(SRC_DIR)/*.c) 
OBJECTS = $(SOURCES:$(SRC_DIR/%.c=$(OBJ_DIR)/%.o))
HEADERS = $(wildcard $(INCLUDEDIR)/*.h)

# LIB Names
STATIC_LIB = $(BUILD_DIR)/lib/$(LIB_NAME).a
SHARED_LIB = $(BUILD_DIR)/lib/$(LIB_NAME).so

all: static shared

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile .o files
$(OBJ_DIR)%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

static: $(STATIC_LIB)

$(STATIC_LIB): $(OBJECTS) | $(BUILD_DIR)
	ar rcs $@ $^

shared: $(SHARED_LIB)

$(SHARED_LIB): $(OBJECTS) | $(BUILD_DIR)
	$(CC) -shared -o $@ $^

install: all
	# make folders
	install -d $(DESTDIR)$(LIBDIR)
	install -d $(DESTDIR)$(INCLUDEDIR)

	# install libs 
	install -m 644 $(STATIC_LIB) $(DESTDIR)$(LIBDIR)/
	install -m 755 $(SHARED_LIB) $(DESTDIR)$(LIBDIR)/

	# headers
	install -m 644 $(HEADERS) $(DESTDIR)$(INCLUDEDIR)

	@if [ "$$(id -u)" = "0" ]; then \
		ldconfig; \
	else \
		echo "Run 'sudo ldconfig' to update library chache"; \
	fi

uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/lib/$(LIB_NAME).a
	rm -f $(DESTDIR)$(LIBDIR)/lib/$(LIB_NAME).so
	rm -f $(DESTDIR)$(INCLUDEDIR)/$(notdir $(HEADERS))
	
	@if [ "$$(id -u)" = "0" ]; then \
		ldconfig; \
	fi

clean:
	rm -rf $(BUILD_DIR)

help:
	@echo "Available target: "
	@echo "  all 			- Build both static and shared libraries"
	@echo "  static			- Build static library (.a)"
	@echo "  shared 		- Build shared library (.so)"
	@echo "  install		- Install libraries and headers" 
	@echo "  uninstall		- Remove installed files"
	@echo "  clean 			- Remove build files"

.PHONY all static shared install uninstall clean help

