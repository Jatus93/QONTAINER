#!/bin/bash
make clean
cd Container
qmake Container.pro
make
cd ../IoT
qmake IoT.pro
make
cd ../QModel
qmake QModel.pro
make
cd ../UI
qmake UI.pro
make
cd ..
qmake Qontainer.pro
make
ln -s ./UI/UI

