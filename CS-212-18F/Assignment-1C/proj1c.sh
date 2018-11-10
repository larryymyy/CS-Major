# !/bin/bash

# GReP Command:
# grep -nr '\*:9[0-9]:' passwd_212

IFS=$'\n'
lines=($(grep -nr '\*:9[0-9]:' passwd_212))
