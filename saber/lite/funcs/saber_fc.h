/* Copyright (c) 2018 Anakin Authors, Inc. All Rights Reserved.
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#ifndef ANAKIN_SABER_LITE_FUNCS_SABER_FC_H
#define ANAKIN_SABER_LITE_FUNCS_SABER_FC_H

#include "saber/lite/funcs/op_base.h"

#ifdef USE_ARM_PLACE

#include "saber/lite/funcs/neon/impl/sgemm_arm.h"

namespace anakin{

namespace saber{

namespace lite{

//! input size: 1xk
//! output size: 1xn
//! weights size: nxk
//! bias size: 1xn
//template <typename Dtype>
class SaberFc : public OpBase {
public:
    SaberFc() {}

    SaberFc(const ParamBase* param);

    virtual SaberStatus load_param(const ParamBase* param) override;

    virtual SaberStatus load_param(FILE* fp, const float* weights) override;

    ~SaberFc();

    virtual SaberStatus compute_output_shape(const std::vector<Tensor<CPU, AK_FLOAT>*>& inputs,
                                     std::vector<Tensor<CPU, AK_FLOAT>*>& outputs) override;

    virtual SaberStatus init(const std::vector<Tensor<CPU, AK_FLOAT>*>& inputs, \
        std::vector<Tensor<CPU, AK_FLOAT>*>& outputs, Context &ctx) override;

    virtual SaberStatus dispatch(const std::vector<Tensor<CPU, AK_FLOAT>*>& inputs, \
        std::vector<Tensor<CPU, AK_FLOAT>*>& outputs) override;


private:
    const FcParam* _param;
    Sgemm _gemmer;
    int _m;
    int _k;
    int _n;
};

} //namespace lite

} //namespace saber

} //namespace anakin

#endif // USE_ARM_PLACE

#endif //ANAKIN_SABER_LITE_FUNCS_SABER_FC_H
