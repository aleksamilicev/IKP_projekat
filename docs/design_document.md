# Strukture
1. WR (ID, IP adresa, Port, Status)
2. Hash Mapa WR-ova (kljuc je ID, a vrednost je IP adresa, Port, Status)
3. Dinamicki niz za LB
4. Kruzni bafer za notifikacije i sync


# Osnovni podaci za WR:
- ID, za identifikoranje WR-ova
- IP adresa i port, preko ovoga WR-ovi slusaju zahteve od LB-a
- Status, indikator da li je WR trenutno aktivan ili neaktivan

# Struktura za cuvanje liste WR-ova:
- Hash Mapa, brza pretraga WR-ova po ID-u
- Kljuc nam je ID WR-a
- Vrednost nam je struktura WR-a(IP adresa, port, status)
- Operacije su dodavanje WR-a, brisanje i pretraga

# Centralna struktura za LB
- Dinamicki niz
Zašto dinamička lista (ili niz)?
Jednostavnost u implementaciji:
    LB mora pratiti samo osnovne informacije o WR-ovima, poput njihovih ID-ova, IP adresa, i portova.
    Dinamička lista omogućava lako dodavanje i uklanjanje WR-ova.

Round Robin algoritam:
    Algoritam zahteva iteraciju kroz redosled WR-ova, što je jednostavno sa nizom ili listom.

Registrovanje i odjavljivanje WR-ova:
    WR-ovi se dodaju u listu pri registraciji.
    Pri odjavljivanju, WR se uklanja iz liste.