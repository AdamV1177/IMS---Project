# IMS - Projekt

## Autoři

- Adam Včelař (xvcelaa00)
- Ján Skovajsa (xskovaj00)

#### Simulační studie (dokumentace)
- `./study.pdf`

#### Zdrojové soubory simulačního modelu
- `./src/*`

#### Překlad simulačního modelu
```bash
make
```

#### Spuštění simulačního module
Spuštění s výchozími argumenty:
```bash
make run
```
Příklad spuštění s argumenty:
```bash
make run ARGS='-w -s'
```
```bash
make run ARGS='-h'
```
```bash
make run ARGS='-w -s -r 4,4 -m 8,12'
```

