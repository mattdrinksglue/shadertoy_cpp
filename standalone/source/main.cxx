// stl includes
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

// 3rd party includes
#include <cxxopts.hpp>

// shadertoycpp includes
#include "shadertoycpp/shadertoycpp.hxx"

auto main(int argc, char** argv) -> int { 
  // Parse command line inputs

  cxxopts::Options options(*argv, "A program to visualise c++ fragment shaders");

  // clang-format off
  options.add_options()
    ("h,help", "Show help")
    ("s,size", "size (pixels) of render viewport", cxxopts::value<std::string>()->default_value("800,600"))
  ;
  // clang-format on

  auto result = options.parse(argc, argv);

  if (result["help"].as<bool>()) {
    std::cout << options.help() << std::endl;
    return 0;
  }

  auto dims = result["size"].as<std::string>();
  auto w = std::stoi(dims.substr(0, dims.find(',')));
  auto h = std::stoi(dims.substr(dims.find(',')+1, dims.size()-1));

  glfwInit();

  // Create App, render
  app_t app(800, 600);

  app.run();

  return 0;
}
