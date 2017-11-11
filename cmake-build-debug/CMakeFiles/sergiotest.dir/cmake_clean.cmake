file(REMOVE_RECURSE
  "sergiotest.pdb"
  "sergiotest.exe"
  "libsergiotest.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/sergiotest.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
