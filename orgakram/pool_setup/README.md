# Pool aufsetzen:

Wie jedes Jahr steht bestimmt auch dieses Jahr wieder ein Programmiervorkurs an! :partying_face:

Damit bei diesem alles Rund läuft muss man diesen _im Vorraus_ zum Stattfinden des Kurses aufsetzten und den fertigen Setup mal testen, dann spart man sich viel Stress!

## Folgende Dateien müssen vor dem Ausführen bearbeitet werden:

- Erzeugen des Skripts und der Dateien
  ```
  make nodir  # Lösche die alten Dateien
  make zip    # Erzeuge die neuen Filestruktur & den Ordner "vorkurs"
              # & Baue das Zipfile für die Webseite
  make script # Baue das Skript "vorkurs.pdf"
  ```
- `site.yml`:
    - Pfad zum Skript
    - Pfad zu den Source Files
    - Die SSH-Keys der Tutoren
- Die Configdateien in `./roles/pool-setup/files/` bei Bedarf!
- Die Hostsdatei in `inventory/hosts.ini`, s.d. dort das vergebene Präfix und die Anzahl der Nutzer stimmt

### Häufige Fehler

- Inkompatible Toolchains verwenden. In [Issue #118](https://github.com/FachschaftMathPhysInfo/Programmiervorkurs/issues/118) ist der Fall aufgetreten, dass auf dem Pool eine weit ältere Compilerversion lief als auf dem Rechner, mit dem `make zip` ausgeführt wurde. Dadurch konnten das Objectfile in Lektion 17 nicht richtig gelinkt werden.

## Erstes Ausführen:

1. Installiere dir das Ansible Tooling auf dem Computer
2. Verbinde dich mit dem [VPN der Uni](https://www.urz.uni-heidelberg.de/de/service-katalog/netzwerk/vpn-virtual-private-network)
3. `$ ansible-playbook --ask-pass site.yml` und gib dort das für die Nutzer gesetzte Passwort ein.

## Jedes weitere Mal:

Da der erste Run die SSH-Keys installiert haben sollte, muss nun kein separates Passwort mehr eingegeben werden.
Es ist sinnvoll das auch auszunutzen, da die Nutzer:innen im Programmierkurs ja vermutlich auch ihr Passwort für ihren Nutzer ändern!

1. Verbinde dich mit dem [VPN der Uni](https://www.urz.uni-heidelberg.de/de/service-katalog/netzwerk/vpn-virtual-private-network)
2. `$ ansible-playbook site.yml`

