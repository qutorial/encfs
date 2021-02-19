#!/bin/bash -eu

: ${CMAKE:=cmake}
: ${CHECK:=false}
: ${INTEGRATION:=true}

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
fi

cd ..

echo
echo 'Everything looks good, you can install via "make install -C build".'
