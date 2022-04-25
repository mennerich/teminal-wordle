//
// Created by menneric on 4/24/22.
//

#ifndef TWORD_MAIN_H
#define TWORD_MAIN_H

bool validate_guess(const std::string &);

static void usage(const std::string &);

void parse_arguments(int &, char **);

int game();

#endif //TWORD_MAIN_H
