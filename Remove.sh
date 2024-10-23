#!/bin/bash

# Uninstall library
arduino-cli lib uninstall me_List

# Uninstall dependencies
arduino-cli lib uninstall \
  me_MemorySegment \
  me_InstallStandardStreams \
  me_UartSpeeds \
  me_BaseTypes
