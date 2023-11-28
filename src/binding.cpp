#include <algorithm>
#include <emscripten/bind.h>

#include "opencv2/core.hpp"

#include "binding.hpp"
#include "adding.h"
#include "sdk.hpp"

using namespace cv;
using namespace emscripten;

// namespace binding_utils
// {
//   template <typename T>
//   emscripten::val matData(const cv::Mat &mat)
//   {
//     return emscripten::val(emscripten::memory_view<T>((mat.total() * mat.elemSize()) / sizeof(T), (T *)mat.data));
//   }

//   std::string getBuildInformation() {
//     return cv::getBuildInformation();
//   }

//   void run(Resizer& resizer)
//   {
//     resizer.run();
//   }
// }

// EMSCRIPTEN_BINDINGS(binding_utils)
// {
//   emscripten::class_<Resizer>("Resizer")
//     .constructor<cv::Mat>()
//     .function("run", emscripten::select_overload<void(Resizer&)>(&binding_utils::run));

//   emscripten::class_<cv::Mat>("Mat")
//     .constructor<int, int, int>()

//     .property("rows", &cv::Mat::rows)
//     .property("cols", &cv::Mat::cols)
//     .property("data", &binding_utils::matData<unsigned char>)
//     .property("data8S", &binding_utils::matData<char>)
//     .property("data16U", &binding_utils::matData<unsigned short>)
//     .property("data16S", &binding_utils::matData<short>)
//     .property("data32S", &binding_utils::matData<int>)
//     .property("data32F", &binding_utils::matData<float>)
//     .property("data64F", &binding_utils::matData<double>);

//   emscripten::function("getBuildInformation", &binding_utils::getBuildInformation);

//   emscripten::constant("CV_8UC1", CV_8UC1);
//   emscripten::constant("CV_8UC2", CV_8UC2);
//   emscripten::constant("CV_8UC3", CV_8UC3);
//   emscripten::constant("CV_8UC4", CV_8UC4);
// }

#ifdef __cplusplus
extern "C"
{
#endif

  EMSCRIPTEN_KEEPALIVE
  void binding_resize(cv::Mat input)
  {
    Resizer resizer(input);
    resizer.run();
  }

  int binding_add(int a, int b)
  {
    return Sdk::add_public(a, b);
  }

#ifdef __cplusplus
}
#endif