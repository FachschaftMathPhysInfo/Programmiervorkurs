# Pool aufsetzen:

Wie jedes Jahr steht bestimmt auch dieses Jahr wieder ein Programmiervorkurs an! :party:
Damit bei diesem alles Rund läuft muss man diesen _im Vorraus_ zum Stattfinden des Kurses aufsetzten und den fertigen Setup mal testen, dann spart man sich viel Stress!

## Folgende Dateien müssen vor dem Ausführen bearbeitet werden:

- `site.yml`:
    - Pfad zum Skript
    - Pfad zu den Source Files
    - SSH-Keys
- Die Configdateien in `./roles/pool-setup/files/` bei Bedarf!
- Die Hostsdatei in `inventory/hosts.ini`, s.d. dort das vergebene Präfix und die Anzahl der Nutzer stimmt

## Erstes Ausführen:

1. Installiere dir das Ansible Tooling auf dem Computer
2. Verbinde dich mit dem [VPN der Uni](https://www.urz.uni-heidelberg.de/de/service-katalog/netzwerk/vpn-virtual-private-network)
3. `$ ansible-playbook --ask-pass site.yml` und gib dort das für die Nutzer gesetzte Passwort ein.

## Jedes weitere Mal:

Da der erste Run die SSH-Keys installiert haben sollte, muss nun kein separates Passwort mehr eingegeben werden.
Es ist sinnvoll das auch auszunutzen, da die Nutzer:innen im Programmierkurs ja vermutlich auch ihr Passwort für ihren Nutzer ändern!

1. Verbinde dich mit dem [VPN der Uni](https://www.urz.uni-heidelberg.de/de/service-katalog/netzwerk/vpn-virtual-private-network)
2. `$ ansible-playbook site.yml`

