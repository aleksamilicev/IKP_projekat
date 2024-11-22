# Tok Programa
1. Inicijalizacija LB i WR komponenti(npr WR1, WR2, ... WRN), N je proizvoljan(random) broj

2. Klijent šalje zahtev, šalje podatke za skladištenje LB-u, pr:
ZAHTEV: {ID_podatka: 1, sadržaj: "....1"},
LB prima zahtev na svom portu 5059.

3. Distribucija podataka(Round Robin algoritam)
- LB koristi RR, 1. zahtev se šalje WR1, 2. zahtev se šalje WR2, 3. zahtev se šalje WR1

4. Skladištenje podataka u WR
- WR1 prima podatke od LB-a i skladišti ih u svoj lokalni prostor

5. Sinhronizacija sa drugim WR-ovima
- WR1 šalje notifikaciju svim drugim WR-ovima o novom podatku
- WR2 prima notifikaciju od WR1 i ažurira svoje skladište (appenduje podatke od WR1)

6. Obaveštenje LB-a
- Kada WR1 uspešno skladišti podatak i pošalje notifikaciju, šalje potvrdu LB-u
- LB beleži(loguje) da je podatak ispravno obrađen

7. Inicijalno dodavanje WR-a
- Novi WR se registruje kod LB-a i šalje svoj IP adr i Port
- LB dodaje WR u svoj dinamički niz(listu) i inicira REDISTRIBUCIJU podataka

7.5 Klijent šalje novi zahtev

8. Rezultat
- Na kraju, svi WR-ovi imaju identično skladište podataka




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