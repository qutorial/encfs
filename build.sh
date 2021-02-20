#!/bin/bash -eu

: ${CMAKE:=cmake}
: ${CHECK:=false}

if [[ -z "$(printenv | grep ENCFS_SKIP_INTEGRATION)" ]]; then
  : ${INTEGRATION:=true}
else
  : ${INTEGRATION:=false}
fi

while ! which ${CMAKE};  
do 
  echo "Please, install cmake first."
  exit 1 
done

${CMAKE} --version

CFG=$*
if [[ "$CHECK" == "true" ]]; then
  CFG="-DLINT=ON $CFG"
fi

rm -rf build
mkdir build

cd build
${CMAKE} .. ${CFG}
make -j2
make unittests
make test
if [[ "$INTEGRATION" == "true" ]]; then
  make integration
else
  echo "Skipping integration tests"
fi

cd ..

echo
echo 'Everything looks good, you can install via "make install -C build".'
