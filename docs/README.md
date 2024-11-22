# IKP_projekat
Load Balancing

# Pokretanje projekta TUTORIAL:
1. Pokrenuti LB        "./lb_main"
2. Pokrenuti WR        "./wr_main"
3. Pokrenuti Testove   "./integration_tests"


# Folder - File struktura:
Preglednije u Visual Studio Code Editoru
LoadBalancer_Project/
├── src/                       # Izvorni kod
│   ├── load_balancer/         # Code za Load Balancer
│   │   ├── lb_main.c          # Ulazna tačka za Load Balancer
│   │   ├── lb_utils.c         # Pomoćne funkcije za Load Balancer
│   │   ├── lb_utils.h         # Header fajl za pomoćne funkcije
│   │   ├── lb_round_robin.c   # Implementacija Round Robin algoritma
│   │   ├── lb_round_robin.h   # Header fajl za Round Robin algoritam
│   │   ├── lb_registration.c  # Registracija i odjava WR-ova
│   │   ├── lb_registration.h  # Header fajl za registraciju WR-ova
│   │   ├── lb_sync.c          # Sinhronizacija podataka među WR-ovima
│   │   ├── lb_sync.h          # Header fajl za sinhronizaciju podataka
│   |
│   ├── worker/                # Code za Worker komponente
│   │   ├── wr_main.c          # Ulazna tačka za Worker
│   │   ├── wr_utils.c         # Pomoćne funkcije za Worker
│   │   ├── wr_utils.h         # Header fajl za pomoćne funkcije
│   │   ├── wr_storage.c       # Funkcije za lokalno skladištenje podataka
│   │   ├── wr_storage.h       # Header fajl za skladištenje
│   │   ├── wr_sync.c          # Ažuriranje podataka među WR-ovima
│   │   ├── wr_sync.h          # Header fajl za ažuriranje
│   │
│   ├── common/                # Zajedničke funkcionalnosti
│       ├── network.c          # Funkcije za mrežnu komunikaciju (socketi)
│       ├── network.h          # Header fajl za mrežnu komunikaciju
│       ├── logger.c           # Funkcije za logovanje
│       ├── logger.h           # Header fajl za logovanje
│       ├── data_structures.c  # Strukture podataka (liste, mape)
│       ├── data_structures.h  # Header fajl za strukture podataka
│       ├── config.h           # Konfiguracione konstante i makroi
│
├── tests/                     # Testovi
│   ├── lb_tests.c             # Testovi za Load Balancer
│   ├── wr_tests.c             # Testovi za Worker
│   ├── integration_tests.c    # Testovi integracije LB-a i WR-ova
│
├── build/                     # Build fajlovi (kompajlirani fajlovi)
│   ├── Makefile               # Makefile za build sistema
│
├── docs/                      # Dokumentacija
│   ├── README.md              # Osnovne informacije o projektu
│   ├── design_document.md     # Dizajn dokumentacija
│   ├── usage_instructions.md  # Uputstva za korišćenje
│
├── logs/                      # Log fajlovi (dinamički generisani tokom izvršavanja)
│   ├── lb_logs/               # Logovi za Load Balancer
│   ├── wr_logs/               # Logovi za Workere
│
├── scripts/                   # Skripte za automatizaciju
│   ├── run_lb.sh              # Skripta za pokretanje Load Balancer-a
│   ├── run_wr.sh              # Skripta za pokretanje Worker-a
│   ├── test.sh                # Skripta za pokretanje testova
│
└── config/                    # Konfiguracioni fajlovi
    ├── lb_config.json         # Konfiguracija za Load Balancer
    ├── wr_config.json         # Konfiguracija za Workere
