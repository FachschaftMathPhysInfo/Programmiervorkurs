#!/usr/bin/zsh

# Dateien:
#  - ssh_session: Dieses Skript das ausgeführt wird.
#  - poolpw: gibt das Passwort zurück (z.B.: echo "M4thphy\$2015")
#  - keys: enthält alle public keys (je key eine Zeile)
#  - vorkurs: Ordner vom git über make all erzeugt
#  - vorkurs.pdf: Skript, vom git erzeugt
#  - user: binary file, das die Einstellung von gedit speichert
#  - mimeapps.list: welche Dateien wie geöffnet werden sollen

ROOT_PATH=$(realpath .)

# FIXME:
# PREFIX="vk20_0"

# FIXME:
# SSH_KEY_PATH="~/.ssh/chris_fachschaft"

# Treat unset variables as an error
set -o nounset

# Uncomment this to see which exact statement is issued before an error
# set -x


if [[ ! -a "./poolpw" ]]; then
    echo "'poolpw' existiert nicht im aktuellen Verzeichnis!"
    echo "Bitte lege die Datei noch an und schreibe das beantragte Passwort hinein!"
    return 1
fi

if [[ ! -a "../vorkurs.pdf" ]]; then
    echo "'vorkurs.pdf' existiert nicht im überliegenden Verzeichnis!"
    return 1
fi

if [[ ! -a "../vorkurs" ]]; then
    echo "Der Ordner 'vorkurs' existiert nicht im überliegenden Verzeichnis!"
    echo "führe 'make dir' aus"
    return 1
fi

for i in {01..50}; do
    echo "Currently setting up account: "$PREFIX$i
    setsid sshpass -f $ROOT_PATH/poolpw ssh "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de" 'mkdir -pv ~/.ssh'
    cat $ROOT_PATH/keys | setsid sshpass -f $ROOT_PATH/poolpw ssh "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de" 'cat - > ~/.ssh/authorized_keys'

    setsid sshpass -f $ROOT_PATH/poolpw scp -q $ROOT_PATH/../vorkurs.pdf "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de:~/."
    setsid sshpass -f $ROOT_PATH/poolpw scp -q -r $ROOT_PATH/../vorkurs "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de:~/."
    setsid sshpass -f $ROOT_PATH/poolpw ssh "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de" 'mkdir -pv ~/Desktop'
    setsid sshpass -f $ROOT_PATH/poolpw ssh "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de" 'ln --force ~/vorkurs.pdf ~/Desktop/vorkurs.pdf'
    setsid sshpass -f $ROOT_PATH/poolpw ssh "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de" 'ln --force -s ~/vorkurs ~/Desktop/vorkurs'

    setsid sshpass -f $ROOT_PATH/poolpw ssh "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de" 'mkdir -pv ~/.config'
    scp -q -i $SSH_KEY_PATH $ROOT_PATH/mimeapps.list "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de:~/.config/"

    setsid sshpass -f $ROOT_PATH/poolpw ssh "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de" 'mkdir -pv ~/.config/dconf'
    scp -q -i $SSH_KEY_PATH $ROOT_PATH/user "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de:~/.config/dconf/user"
    setsid sshpass -f $ROOT_PATH/poolpw ssh "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de" 'echo "alias g++=\"g++ -std=c++17\"" >> ~/.bashrc'
    setsid sshpass -f $ROOT_PATH/poolpw ssh "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de" 'mkdir -pv ~/.config/xfce4/terminal'
    scp -q -i $SSH_KEY_PATH $ROOT_PATH/terminalrc "$PREFIX${i}"@"pool.iwr.uni-heidelberg.de:~/.config/xfce4/terminal"
    echo "Done setting up account: "$PREFIX$i
done
