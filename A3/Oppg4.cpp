#include <string>
#include <iostream>

using namespace std;

int main() {
  // Oppgave a:
  string word1, word2, word3;
  cout << "Ord 1: " << endl;
  cin >> word1;
  cout << "Ord 2: " << endl;
  cin >> word2;
  cout << "Ord 3: " << endl;
  cin >> word3;
  
  // Oppgave b:
  string sentence = word1 + " " + word2 + " " + word3 + ".";
  cout << sentence << endl;
  
  // Oppgave c:
  cout << "Ord 1 lengde: " << word1.length() << ", Ord 2 lengde: " << word2.length() << ", Ord 3 lengde: " <<  word3.length() << endl;
  cout << "Setningslengde: " << sentence.length() << endl;
  
  // Oppgave d & e:
  string sentence2 = sentence;
  for(size_t i = 9; i < 12; i++) {
    if(i > sentence2.length()) break;
      sentence2[i] = 'x';
  }
  cout << sentence << endl;
  cout << sentence2 << endl;
  
  // Oppgave f:
  auto sentence_start = (sentence.length() > 5) ?
  sentence.substr(0, 5) : sentence.substr(0, sentence.length());
  cout << sentence_start << ", " << sentence << endl;
  
  // Oppgave g:
  auto found = sentence.find("Hallo");
  if(found != string::npos)
    cout << "Hallo er tilstede!" << endl;
  else cout << "Hallo er ikke tilstede.." << endl;
  
  // Oppgave h:
  int sum = 0;
  size_t num = sentence.find("er");
  while(num != string::npos) {
    sum++;
    num = sentence.find("er", num+1);
  }
  cout << "'er' oppstår: " << sum << " ganger.." << endl;
  
  return 0;
}
