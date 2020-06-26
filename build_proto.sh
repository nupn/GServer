SRC_DIR=$PWD
#~/work/protoc/
DST_DIR=$PWD
#~/work/protoc/

~/protobuf/src/protoc --proto_path=${SRC_DIR} --cpp_out=${DST_DIR} ${SRC_DIR}/msg.proto
#protoc --cpp_out=${DST_DIR} ${SRC_DIR}/msg.proto
