#! /bin/bash

function remove(){
  local dir=$1
  for file in ${dir}/*;do
    if [[ -f ${file} && ${file##*.} == "txt" ]];then
      echo ${file} has deleted
      rm ${file}
    elif [[ -d ${file} ]];then
      remove ${file}
    fi
  done
}

remove .
