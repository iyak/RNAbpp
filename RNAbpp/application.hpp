//
//  application.hpp
//  RNAelem
//
//  Created by Hiroshi Miyake on 2016/11/17.
//  Copyright © 2016 Kiryu Lab. All rights reserved.
//

#ifndef application_h
#define application_h

#include"opt_parser.hpp"
#include"bio_sequence.hpp"

namespace iyak {

  class App {

    optparse::OptionParser _parser;

  public:

    VI seq;
    int max_span = 0;
    string energy_file;
    int format = 0;

    enum {
      FORMAT_NONE = 0,
      FORMAT_PYTHON = 1<<0,
      FORMAT_SQRT = 1<<1,
      FORMAT_LOG = 1<<2,
    };

    App(int const argc, char const* argv[]) {

      _parser
      .add_option("-s", "--seq")
      .help("RNA sequence [ACGU]+")
      .dest("seq")
      .set_default("")
      .metavar("String");

      _parser
      .add_option("-m", "--max-span")
      .help("Maximal span of base pair")
      .dest("max_span")
      .set_default(999999)
      .metavar("Int");

      _parser
      .add_option("-e", "--energy-param")
      .help("Energy file name")
      .dest("energy_file")
      .set_default("~T2004~")
      .metavar("File");

      _parser
      .add_option("-p", "--python")
      .help("Output in python vector format")
      .dest("python")
      .action("store_true");

      _parser
      .add_option("-q", "--sqrt")
      .help("Output number is sqrt")
      .dest("sqrt")
      .action("store_true");
      
      _parser
      .add_option("-l", "--log")
      .help("Output number is log")
      .dest("log")
      .action("store_true");

      auto const options = _parser.parse_args(argc, argv);
      auto const args = _parser.args();

      seq_stoi(options["seq"], seq);
      max_span = options.get("max_span");
      energy_file = options["energy_file"];

      if ((bool)options.get("python")) format |= FORMAT_PYTHON;
      if ((bool)options.get("sqrt"))   format |= FORMAT_SQRT;
      if ((bool)options.get("log"))    format |= FORMAT_LOG;
    }
  };
}

#endif /* application_h */
