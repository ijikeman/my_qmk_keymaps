DEFAULT_FOLDER = helix/rev2

HELIX_TOP_DIR := $(patsubst %/,%,$(dir $(lastword $(MAKEFILE_LIST))))
TAP_DANCE_ENABLE = yes
