CUR_DIR := .
INC_DIR := $(CUR_DIR)/inc
SRC_DIR := $(CUR_DIR)/src
BIN_DIR := $(CUR_DIR)/bin
OBJ_DIR := $(CUR_DIR)/obj
LIB_DIR := $(CUR_DIR)/lib
LIB_STATIC_DIR := $(LIB_DIR)/static
LIB_SHARED_DIR := $(LIB_DIR)/shared

LIB_NAME := bstrutils
BIN_NAME_1 := use_shared_lib
BIN_NAME_2 := use_static_lib


create_obj:
	gcc -c -o $(OBJ_DIR)/main.o $(SRC_DIR)/main.c -I $(INC_DIR)
	gcc -c -fPIC $(SRC_DIR)/bstrutils.c -o $(OBJ_DIR)/bstrutils.o -I $(INC_DIR)

create_shared_lib:
	gcc -shared $(OBJ_DIR)/bstrutils.o -o $(LIB_SHARED_DIR)/lib$(LIB_NAME).so

create_static_lib:
	ar rcs $(LIB_STATIC_DIR)/lib$(LIB_NAME).a $(OBJ_DIR)/bstrutils.o $(OBJ_DIR)/main.o

linking_shared_lib:
	gcc $(OBJ_DIR)/main.o -L$(LIB_SHARED_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/$(BIN_NAME_1)

linking_static_lib:
	gcc $(OBJ_DIR)/main.o -L$(LIB_STATIC_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/$(BIN_NAME_2)

clear:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(LIB_SHARED_DIR)/*
	rm -rf $(LIB_STATIC_DIR)/*
	rm -rf $(BIN_DIR)/*



