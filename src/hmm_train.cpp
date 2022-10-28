/**
 * @file src/hmm_train.cpp
 *
 * This is an autogenerated file containing implementations of C++ functions to
 * be called by the R hmm_train binding.
 */
#include <rcpp_mlpack.h>
#define BINDING_TYPE BINDING_TYPE_R
#include <mlpack/methods/hmm/hmm_train_main.cpp>

#define Realloc(p,n,t) (t *) R_chk_realloc( (void *)(p), (R_SIZE_T)((n) * sizeof(t)) )
#define Free(p)        (R_chk_free( (void *)(p) ), (p) = NULL)

// [[Rcpp::export]]
void hmm_train_call(SEXP params, SEXP timers)
{
  util::Params& p = *Rcpp::as<Rcpp::XPtr<util::Params>>(params);
  util::Timers& t = *Rcpp::as<Rcpp::XPtr<util::Timers>>(timers);

  BINDING_FUNCTION(p, t);
}

// Any implementations of methods for dealing with model pointers will be put
// below this comment, if needed.

// Get the pointer to a HMMModel parameter.
// [[Rcpp::export]]
SEXP GetParamHMMModelPtr(SEXP params,
                                   const std::string& paramName,
                                   SEXP inputModels)
{
  util::Params& p = *Rcpp::as<Rcpp::XPtr<util::Params>>(params);
  Rcpp::List inputModelsList(inputModels);
  HMMModel* modelPtr = p.Get<HMMModel*>(paramName);
  for (int i = 0; i < inputModelsList.length(); ++i)
  {
    Rcpp::XPtr<HMMModel> inputModel =
        Rcpp::as<Rcpp::XPtr<HMMModel>>(inputModelsList[i]);
    // Don't create a new XPtr---just reuse the one given as input, so that we
    // don't end up deleting it twice.
    if (inputModel.get() == modelPtr)
      return inputModel;
  }

  return std::move((Rcpp::XPtr<HMMModel>) p.Get<HMMModel*>(paramName));
}

// Set the pointer to a HMMModel parameter.
// [[Rcpp::export]]
void SetParamHMMModelPtr(SEXP params, const std::string& paramName, SEXP ptr)
{
  util::Params& p = *Rcpp::as<Rcpp::XPtr<util::Params>>(params);
  p.Get<HMMModel*>(paramName) = Rcpp::as<Rcpp::XPtr<HMMModel>>(ptr);
  p.SetPassed(paramName);
}

// Serialize a HMMModel pointer.
// [[Rcpp::export]]
Rcpp::RawVector SerializeHMMModelPtr(SEXP ptr)
{
  std::ostringstream oss;
  {
    cereal::BinaryOutputArchive oa(oss);
    oa(cereal::make_nvp("HMMModel",
          *Rcpp::as<Rcpp::XPtr<HMMModel>>(ptr)));
  }

  Rcpp::RawVector raw_vec(oss.str().size());

  // Copy the string buffer so we can return one that won't get deallocated when
  // we exit this function.
  memcpy(&raw_vec[0], oss.str().c_str(), oss.str().size());
  raw_vec.attr("type") = "HMMModel";
  return raw_vec;
}

// Deserialize a HMMModel pointer.
// [[Rcpp::export]]
SEXP DeserializeHMMModelPtr(Rcpp::RawVector str)
{
  HMMModel* ptr = new HMMModel();

  std::istringstream iss(std::string((char *) &str[0], str.size()));
  {
    cereal::BinaryInputArchive ia(iss);
    ia(cereal::make_nvp("HMMModel", *ptr));
  }

  // R will be responsible for freeing this.
  return std::move((Rcpp::XPtr<HMMModel>)ptr);
}


