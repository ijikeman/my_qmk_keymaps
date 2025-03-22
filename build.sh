#!/bin/bash
QMK_VERSION='0.28.0'
QMK_NAME='qmk_firmware'
HOMEDIR='/home/vscode/project/'
REPOSITORY_NAME='qmk'

# HOMEDIRをEscapeしてESCAPE_HOMEDIRに代入する
ESCAPE_HOMEDIR=$(echo $HOMEDIR | sed 's/\//\\\//g')

# 第一引数はキーボード名
args_kb=$1
args_km=$2

# args_kbを/で分割して、最初の要素を取得しkeyboard_nameに代入
keyboard_name=$(echo $args_kb | cut -d'/' -f1)

# qmk_firmware(https://github.com/qmk/qmk_firmware.git)をlatestのみをクローン
# もしqmk_firmwareが存在する場合はスキップ
if [ ! -d "qmk_firmware" ]; then
    git clone -b ${QMK_VERSION} --depth 1 --recurse-submodules https://github.com/qmk/qmk_firmware.git

    # QMK_VERSIONが0.22ならdocker_build.shを入れ替え
    if [ "${QMK_VERSION}" -eq '0.22' ]; then
      rm -f qmk_firmeware/util/docker_build.sh
      cp -p replace_script/${QMK_VERSION}/docker_build.sh qmk_firmware/util/docker_build.sh
    fi
fi

# keyboardsの対象フォルダを入れ替え
rm -rf ${QMK_NAME}/keyboards/${keyboard_name}
cp -Rp ${keyboard_name} ${QMK_NAME}/keyboards/

# qmk_firmwareに移動してコンパイル
cd qmk_firmware

# QMK:v0.22時代の修正 qmk setup時にdocker内の/.localにパーミッションがないとPermission deniedでエラーになる為、マウント用ディレクトリを作成
# if [ ! -d ".local" ]; then
    # mkdir -p .local
# fi

# build hex
bash util/docker_build.sh ${args_kb}:${args_km}
