/* Axestrack Assignment by Riddhi Gupta
*/

#include<bits/stdc++.h>
using namespace std;
#define fr(i, a, b) for(i=a; i<b; i++)
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second
ll min(ll a, ll b){
	return (a<b)?a:b;
}
ll max(ll a, ll b){
	return (a>b)?a:b;
}

//function to find the decimal equivalent of a hex character.
int hex_equivalent(char c){
	if(c<='9'&&c>='0')return c-'0';
	if(c<='f'&&c>='a')return c-'a'+10;
	// if not a valid hex char then some error must have occured in the packet.
	return -1;
}

const ll inf= 9999999999LL;
ll mo=1000000007LL;
string s;
int main(){

	cin>>s;// input the string
	int l, i=0, j, k, length_packet;
	l=s.length();// length of string

	//traverse till end of string
	while(i<l){

		//go on till we find starting characters of packet i.e. 0x90 0x00
		while(i+3<l&&(s[i]!='9'||s[i+1]!='0'||s[i+2]!='0'||s[i+3]!='0'))i++;

		//i+4 and i+5 specify length. If string ends abruptly then break out of loop.
		if(i+5>=l)break;

		//if characters that specify length of packet are not hex, skip the packet
		if(hex_equivalent(s[i+4])==-1||hex_equivalent(s[i+5])==-1){
			i++;
			continue;
		}

		//length_packet is length of packet
		length_packet=hex_equivalent(s[i+4])*16+hex_equivalent(s[i+5]);

		j=i+6;

		//if packet is incomplete but stream(string) ends
		if(j+2*length_packet+3>=l){i++; continue;}
		// if delimiter(0x0d 0x0a) not found, then it was not a valid packet
		if((s[j+2*length_packet]!='0'||s[j+2*length_packet+1]!='d'||s[j+2*length_packet+2]!='0'||s[j+2*length_packet+3]!='a')){
			i++;
			continue;
		}

		//a valid packet has been found, print it.
		for(k=i; (k<j+2*length_packet+4)&&(k<l);k++)cout<<s[k];
			cout<<endl;

		i=k;
	}
}