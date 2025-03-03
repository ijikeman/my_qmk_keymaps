QMK_VERSION='0.22.0'

# 第一引数はキーボード名
keyboard=$1
build=$2
folder=$3

# qmk_firmware(https://github.com/qmk/qmk_firmware.git)をlatestのみをクローン
# もしqmk_firmwareが存在する場合はスキップ
if [ ! -d "qmk_firmware" ]; then
    git clone -b ${QMK_VERSION} --depth 1 --recurse-submodules https://github.com/qmk/qmk_firmware.git
    # vscode-serverの場合はディレクトリパスが変わる為、コメントアウトする
    sed -i -e 's/^qmk_userspace_dir=""/qmk_userspace_dir=""\nqmk_firmware_dir="\/home\/vscode\/project\/qmk\/qmk_firmware\/"/' qmk_firmware/util/docker_cmd.sh
fi

# 引数のフォルダにrules.mkを上書き
cp rules.mk qmk_firmware/keyboards/$1

# キーマップのフォルダにoriginalフォルダを作成
if [ ! -d "qmk_firmware/keyboards/$keyboard/keymaps/original" ]; then
    mkdir qmk_firmware/keyboards/$keyboard/keymaps/original
fi

# originalフォルダにキーボード名.keymap.cをコピー
#cp $keyboard.keymap.c qmk_firmware/keyboards/$keyboard/keymaps/original/keymap.c
# config.hをコピー
#cp $keyboard.config.h qmk_firmware/keyboards/$keyboard/keymaps/original/config.h

# qmk_firmwareに移動
cd qmk_firmware
util/docker_build.sh $1:default