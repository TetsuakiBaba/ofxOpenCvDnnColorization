#!/bin/bash
rm  ./Examples/single_image/bin/data/colorization_release_v2.caffemodel
rm  ./Examples/single_image/bin/data/colorization_deploy_v2.prototxt
rm  ./Examples/videofile/bin/data/colorization_release_v2.caffemodel
rm  ./Examples/videofile/bin/data/colorization_deploy_v2.prototxt

rm -fR ./Examples/single_image/bin/single_image*.app
rm -fR ./Examples/videofile/bin/videofile*.app
echo "done"