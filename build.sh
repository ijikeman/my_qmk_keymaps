#!/bin/bash
QMK_VERSION='0.22.0'
QMK_NAME='qmk_firmware'
HOMEDIR='/home/vscode/project/'
REPOSITORY_NAME='qmk'

# HOMEDIRをEscapeする
ESCAPE_HOMEDIR=``

# 第一引数はキーボード名
args_kb=$1
args_km=$2

# qmk_firmware(https://github.com/qmk/qmk_firmware.git)をlatestのみをクローン
# もしqmk_firmwareが存在する場合はスキップ
if [ ! -d "qmk_firmware" ]; then
    git clone -b ${QMK_VERSION} --depth 1 --recurse-submodules https://github.com/qmk/qmk_firmware.git
fi
# vscode-serverの場合はディレクトリパスが変わる為、コメントアウトする
sed -i -e 's/^qmk_userspace_dir=""/qmk_userspace_dir=""\nqmk_firmware_dir="${ESCAPE_HOMEDIR}\/${REPOSITORY_NAME}\/qmk_firmware\/"/' qmk_firmware/util/docker_cmd.sh

# 引数のフォルダを入れ替え
rm -rm ${QMK_NAME}/keyboards/${args_kd}

# キーマップのフォルダにoriginalフォルダを作成

# qmk_firmwareに移動
cd qmk_firmware
util/docker_build.sh ${args_kb}:${args_km}
