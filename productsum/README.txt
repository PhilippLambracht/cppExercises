== productsum - Projekt zum Vergleich der Performanzsteigerung durch parallels Programmieren.

ext/gtest				- Externes CMake-Projekt zur Erstellung der Bibliotheken des googletest-Frameworks zum
								  Testen von C++-Code. Aktuell wird Version 1.7 verwendet und direkt aus dem öffentlichen
								  SVN von Google heruntergeladen. Zum Erstellen ist demnach eine Internetverbindung notewendig.

lib/productsum	- Bibliothek zum Berechnen der Produktsumme für einen vorgegebenen Teil eines Arrays.
lib/timing			- Bibliothek zum Nehmen von Zeitstempeln.

test/productsum	- Test-Routinen zum Testen der Bibliothek productsum-lib.
test/timing			- Test-Routinen zum Testen der Bibliothek timing-lib.

src/cli.cpp			- Implementierung eine Kommandozeilen-Schnittstelle zur einfachen parametrisierten Ausführung
								  der Produktsummenberechnung. Mit Hilfe von Parametern kann die Größe des Testarrays und die
								  Anzahl der zu verwendenden Threads angegeben werden.

== Kompilieren

Im Wurzelverzeichnis des Projeks müssen die folgenden Befehle eingegebenen werden:

# Erstellen des build-Ordners, falls dieser nicht bereits existiert.
mkdir -p build

# In den build-Ordner navigieren.
cd build

# CMake aufrufen unter Angabe des Pfades, unter dem sich die Hauptdatei CMakeLists.txt des zu erstellenden
# CMake-Projekts befindet. In diesem Fall im übergeordneten Verzeichnis, das mit ".." angegeben wird.
cmake .. 

# Mit Hilfe der erstellten Make-Datei das Projekt kompilieren. Hierbei wird googletest aus dem offiziellen
# SVN-Repository von Google in der Version 1.7 ausgecheckt. Eine Internetverbindung ist somit mindestens für
# den ersten Kompiliervorgang notwendig.
make

# Anschließend können die erstellten ausführbaren Dateien aufgerufen werden.
# Zum Testen der Bibliotheken:
./bin/productsum-test

# Zum Messen der Zeiten für die sequentielle und parallele Berechnung der Produktsumme:
./bin/productsum-cli -n <THREADS> -s <ARRAY_LENGTH>
