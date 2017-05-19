//
//  main.cpp
//  RNAelem
//
//  Created by Hiroshi Miyake on 2016/11/09.
//  Copyright © 2016 Kiryu Lab. All rights reserved.
//

  enum {
    DBG_NONE = 0,
    DBG_NO_WEIGHT = 1<<0,
    DBG_NO_ENE = 1<<1, // obsolete
    DBG_FIX_RSS = 1<<2,
    DBG_VERBOSE = 1<<3,
    DBG_NO_TURN = 1<<4,
    DBG_PROOF = 1<<5,
    DBG_ARRAY = 1<<6,
    DBG_KEEP_TMP = 1<<7,
    DBG_CORE_FILE = 1<<8,
    DBG_NO_LOGSUM = 1<<9,
  };
  enum {
    debug =
    DBG_NONE,
  };
  
#include<iostream>
#include"util.hpp"
#include"application.hpp"
#include"energy_model.hpp"
using namespace iyak;

double pr(int format, double x) {
  if (not (format&App::FORMAT_LOG)) x = exp(x);
  if (format&App::FORMAT_SQRT) x = sqrt(x);
  return x;
}

int main(int const argc, char const* argv[]) {
  try {
    App app(argc, argv);
    
    EnergyModel e;
    e.set_param_file(app.energy_file);
    e.set_max_pair(app.max_span);
    e.set_seq(app.seq);
    e.calc_BPP();

    cout.precision(17);
    if (app.format&App::FORMAT_PYTHON) {
      cout << "[";
      for (int i=0; i<size(app.seq); ++i) {
        cout << "[";
        for (int j=1; j<=size(app.seq); ++j) {
          cout << pr(app.format, e.lnBPP(i,j));
          if (j<size(app.seq)) cout << ",";
        }
        cout << "]";
        if (i<size(app.seq)-1) cout << ",";
      }
      cout << "]\n";
    }
    
    else {
      for (int i=0; i<size(app.seq); ++i) {
        for (int j=1; j<=size(app.seq); ++j) {
          if (app.gt < exp(e.lnBPP(i,j)))
            dat0(i,j-1,pr(app.format, e.lnBPP(i,j)));
        }
      }
    }
  } catch (std::runtime_error& ee) {
    std::cerr << ee.what();
    exit(1);
  }
  return 0;
}
