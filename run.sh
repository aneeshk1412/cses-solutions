g++ --std=c++17 "$1" -o main
./main <input.txt >output.txt
rm -f main