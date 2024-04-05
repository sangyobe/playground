#!/bin/bash

# Usage:

# ./intrin.sh _mm_shuffle_epi8      # output: -mssse3
# ./intrin.sh _mm_cvtepu8_epi32     # output: -msse4.1
# ./intrin.sh _mm_loadu_ps          # output: -msse
# ./intrin.sh _mm_clmulepi64_si128  # output: -mpclmul
# ./intrin.sh _mm256_loadu_si256    # output: -mavx
# ./intrin.sh _mm512_and_ps         # output: -mavx512dq



get_instruction ()
{
    [ -z "$1" ] && exit
    func_name="$1 "

    header_file=`grep --include=\*intrin.h -Rl "$func_name" /usr/lib/gcc | head -n1`
    [ -z "$header_file" ] && exit
    >&2 echo "find in: $header_file"

    target_directive=`grep "#pragma GCC target(\|$func_name" $header_file | grep -B 1 "$func_name" | head -n1`
    echo $target_directive | grep -o '"[^,]*[,"]' | sed 's/"//g' | sed 's/,//g'
}

instruction=`get_instruction $1`
if [ -z "$instruction" ]; then
    echo "Error: function not found: $1"
else
    echo "add this option to gcc: -m$instruction"
fi