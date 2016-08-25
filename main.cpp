#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <sstream>

using namespace std;

class ConnectionPolicy {
public:
    class ReconnectParam {
        int interval = 0;
        int attempts = -1;
        ostream & puts(ostream & s){ return s << "(Interval = " << setw(3) << interval << ", NumAttempts = " << setw(3) << attempts << ")"; }
    public:

        ReconnectParam(int seconds, int times): interval(seconds),attempts(times){}

        friend ostream & operator<<(ostream & s, ReconnectParam & rp){ return rp.puts(s); }
    };

    pair<ReconnectParam, string> next() {
        auto pair = make_pair(reconnect_params.front(), peers.front());

        if (num_retotates < reconnect_params.size() - 1) {
            rotate(reconnect_params.begin(), reconnect_params.begin()+1, reconnect_params.end());
            num_retotates++;
        }
        rotate(peers.begin(), peers.begin()+1, peers.end());

        return pair;
    }

    ConnectionPolicy(string & pattern, vector<string> & peervector): reconnect_pattern(pattern), peers(peervector){
        reconnect_params = parse_pattern(reconnect_pattern);
    }

    vector<ReconnectParam> & parse_pattern(string pattern){

        vector<ReconnectParam> paramvector;

        stringstream patternstream(pattern);
        string item;
        for (;getline(patternstream, item, ',');) {
            stringstream itemstream(item);

            string item_interval;
            string item_attempts;
            getline(itemstream, item_interval, '*');
            getline(itemstream, item_attempts, '*');

            paramvector.push_back(ReconnectParam(stoi(item_interval), stoi(item_attempts)));

        }
        reconnect_params = paramvector;
        return reconnect_params;
    }

private:
    int num_retotates = 0;
    string reconnect_pattern = "";
    vector<ReconnectParam> reconnect_params = {{5,3},{5,3},{10,5},{10,5},{60,5},{60,5},{600,-1}};
    vector<string> peers = {"tcp://127.0.0.1:7"};
};

int main()
{
    string pattern = "5*3, 5*3,10*5 ,10*5,60*5,60*5,600*10";
    vector<string> peervector = {"tcp://127.0.0.1:7","tcp://127.0.0.1:9"};
    ConnectionPolicy connpolicy(pattern, peervector);
    for (int i = 0; i < 10; i++) {
        pair<ConnectionPolicy::ReconnectParam, string> param_peer_pair = connpolicy.next();
        cout << "|=> [" << param_peer_pair.second << "] == " << param_peer_pair.first << endl;
    }
}

