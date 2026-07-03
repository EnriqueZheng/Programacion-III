#!/usr/bin/env bash

project_name='poo2_unit6_adaptadores_poo_v2021_2'
source_code='
        P1.h P1.cpp
        P2.h P2.cpp
        P3.h P3.cpp
        P4.h P4.cpp
        P5.h P5.cpp
        P6.h P6.cpp
        stack_utec.h queue_utec.h
  '
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}
