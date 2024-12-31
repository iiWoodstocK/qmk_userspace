SRC += iiwoodstock.c

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += rgb_matrix_user.c
endif

ifeq ($(strip $(IDLE_TIMEOUT_ENABLE)), yes)
    OPT_DEFS += -DIDLE_TIMEOUT_ENABLE
endif