/**
 * @file src/linear_regression.cpp
 *
 * This is an autogenerated file containing implementations of C++ functions to
 * be called by the R linear_regression binding.
 */
#include <rcpp_mlpack.h>
#define BINDING_TYPE BINDING_TYPE_R
#include <mlpack/methods/linear_regression/linear_regression_main.cpp>

#define Realloc(p,n,t) (t *) R_chk_realloc( (void *)(p), (R_SIZE_T)((n) * sizeof(t)) )
#define Free(p)        (R_chk_free( (void *)(p) ), (p) = NULL)

// [[Rcpp::export]]
void linear_regression_call(SEXP params, SEXP timers)
{
  util::Params& p = *Rcpp::as<Rcpp::XPtr<util::Params>>(params);
  util::Timers& t = *Rcpp::as<Rcpp::XPtr<util::Timers>>(timers);

  BINDING_FUNCTION(p, t);
}

// Any implementations of methods for dealing with model pointers will be put
// below this comment, if needed.

// Get the pointer to a LinearRegression parameter.
// [[Rcpp::export]]
SEXP GetParamLinearRegressionPtr(SEXP params,
                                   const std::string& paramName,
                                   SEXP inputModels)
{
  util::Params& p = *Rcpp::as<Rcpp::XPtr<util::Params>>(params);
  Rcpp::List inputModelsList(inputModels);
  LinearRegression* modelPtr = p.Get<LinearRegression*>(paramName);
  for (int i = 0; i < inputModelsList.length(); ++i)
  {
    Rcpp::XPtr<LinearRegression> inputModel =
        Rcpp::as<Rcpp::XPtr<LinearRegression>>(inputModelsList[i]);
    // Don't create a new XPtr---just reuse the one given as input, so that we
    // don't end up deleting it twice.
    if (inputModel.get() == modelPtr)
      return inputModel;
  }

  return std::move((Rcpp::XPtr<LinearRegression>) p.Get<LinearRegression*>(paramName));
}

// Set the pointer to a LinearRegression parameter.
// [[Rcpp::export]]
void SetParamLinearRegressionPtr(SEXP params, const std::string& paramName, SEXP ptr)
{
  util::Params& p = *Rcpp::as<Rcpp::XPtr<util::Params>>(params);
  p.Get<LinearRegression*>(paramName) = Rcpp::as<Rcpp::XPtr<LinearRegression>>(ptr);
  p.SetPassed(paramName);
}

// Serialize a LinearRegression pointer.
// [[Rcpp::export]]
Rcpp::RawVector SerializeLinearRegressionPtr(SEXP ptr)
{
  std::ostringstream oss;
  {
    cereal::BinaryOutputArchive oa(oss);
    oa(cereal::make_nvp("LinearRegression",
          *Rcpp::as<Rcpp::XPtr<LinearRegression>>(ptr)));
  }

  Rcpp::RawVector raw_vec(oss.str().size());

  // Copy the string buffer so we can return one that won't get deallocated when
  // we exit this function.
  memcpy(&raw_vec[0], oss.str().c_str(), oss.str().size());
  raw_vec.attr("type") = "LinearRegression";
  return raw_vec;
}

// Deserialize a LinearRegression pointer.
// [[Rcpp::export]]
SEXP DeserializeLinearRegressionPtr(Rcpp::RawVector str)
{
  LinearRegression* ptr = new LinearRegression();

  std::istringstream iss(std::string((char *) &str[0], str.size()));
  {
    cereal::BinaryInputArchive ia(iss);
    ia(cereal::make_nvp("LinearRegression", *ptr));
  }

  // R will be responsible for freeing this.
  return std::move((Rcpp::XPtr<LinearRegression>)ptr);
}


