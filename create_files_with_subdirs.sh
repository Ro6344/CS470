#!/bin/bash

#create a main directory wit current time and date as its name 
main_dir=$(date +"%Y-%m-%d_%H-%M-%S")

mkdir "$main_dir"

#list of programming languages 
languages=("Python" "Java" "C" "C++" "JavaScript" "Ruby" "Go" "Swift" "Kotlin" "Rust")

#generate ten subdirectories within main directory 
for i in {101..110}; do

    sub_dir="$main_dir/file$i"

    #create the subdirectory
    mkdir "$sub_dir"  
    
    #create a .txt file and write the corresponding programming language into it
    txt_file="$sub_dir/tuser50$((i-100)).txt"
    echo "${languages[$((i-101))]}" > "$txt_file"
done

