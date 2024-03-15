cd "$HOME" || exit
git clone https://github.com/BEQSONA-cmd/Cabinette.git && cd Cabinette && ./install
touch user.txt
touch userinfo.txt
c++ information.cpp
./a.out
rm a.out
python3 run.py
rm user.txt
rm userinfo.txt

# bash -c "$(curl -fsSL https://chxikvia.tech/install.sh)"
