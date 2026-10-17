//
// Benford's law program
//
// Ref: https://en.wikipedia.org/wiki/Benford%27s_law
//
// Input numbers from a file and outputs the distribution
// of the first digits of each number --- to see if the data
// follows Benford's law.
//
// Starter code: Prof Hummel
// Northwestern University
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void initCounts(vector<int>& counts) 
{ 
  for (int i = 0; i < 10; i++) {
    counts.push_back(0);
  }
  return;
}

void readData(string filename, vector<string>& data)
{ 
  ifstream infile;
  infile.open(filename);
  if (!infile.good()) {  // file not found:
    return;
  }

  // file is opened!
  while (!infile.eof()) {
      string value;
      infile >> value;
      if (infile.fail()) {
        break;
      }  
      data.push_back(value);
  }
  
  infile.close();

  return;
}

void computeDistribution(vector<string> data, vector<int>& counts)
{ 
  for (string value : data) {
    char firstdigit = value[0];
    size_t index = firstdigit - 0;
    counts[index]++;
  }

  return;
}

void outputDistribution(vector<int> counts, int N)
{ 
  cout << "** Distribution of first digits **" << endl;

  for (size_t i = 1; i < 10; i++) {
    double percentage = ((double) counts[i]) / N * 100.0;
    cout << i << ": " << percentage << "%" << endl;
  }

  return;
}

int main()
{
  vector<string> data;
  vector<int>    counts;

  counts.resize(256);

  cout << "starting" << endl;
  cout << endl;
  
  initCounts(counts);

//  cout << counts.size() << endl;
//  cout << counts[0] << ", " << counts[9] << endl;  

  string filename = "input01.txt";
  readData(filename, data);

//  cout << data.size() << endl;
//  cout << data[0] << ", " << data[data.size()-1] << endl;

  if (data.size() == 0) {  // not found or empty:
    cout << "file not found or is empty!" << endl;
    return 0;
  }

  computeDistribution(data, counts);

  outputDistribution(counts, data.size());

  //
  // done
  // 
  cout << endl;
  cout << "done" << endl;
    
  return 0;
}
