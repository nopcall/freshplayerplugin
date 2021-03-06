/*
 * Copyright © 2013-2014  Rinat Ibragimov
 *
 * This file is part of FreshPlayerPlugin.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef FPP__PPB_VAR_H
#define FPP__PPB_VAR_H

#include <ppapi/c/ppb_var.h>
#include <ppapi/c/dev/ppb_var_deprecated.h>


void
ppb_var_add_ref(struct PP_Var var);

void
ppb_var_release(struct PP_Var var);

struct PP_Var
ppb_var_var_from_utf8_1_1(const char *data, uint32_t len);

struct PP_Var
ppb_var_var_from_utf8_1_0(PP_Module module, const char *data, uint32_t len);

const char *
ppb_var_var_to_utf8(struct PP_Var var, uint32_t *len);

bool
ppb_var_has_property(struct PP_Var object, struct PP_Var name, struct PP_Var *exception);

bool
ppb_var_has_method(struct PP_Var object, struct PP_Var name, struct PP_Var *exception);

struct PP_Var
ppb_var_get_property(struct PP_Var object, struct PP_Var name, struct PP_Var *exception);

void
ppb_var_get_all_property_names(struct PP_Var object, uint32_t *property_count,
                               struct PP_Var **properties, struct PP_Var *exception);

void
ppb_var_set_property(struct PP_Var object, struct PP_Var name, struct PP_Var value,
                     struct PP_Var *exception);

void
ppb_var_remove_property(struct PP_Var object, struct PP_Var name, struct PP_Var *exception);

struct PP_Var
ppb_var_call(struct PP_Var object, struct PP_Var method_name, uint32_t argc, struct PP_Var *argv,
             struct PP_Var *exception);

struct PP_Var
ppb_var_construct(struct PP_Var object, uint32_t argc, struct PP_Var *argv,
                  struct PP_Var *exception);

bool
ppb_var_is_instance_of(struct PP_Var var, const struct PPP_Class_Deprecated *object_class,
                       void **object_data);

struct PP_Var
ppb_var_create_object(PP_Instance instance, const struct PPP_Class_Deprecated *object_class,
                      void *object_data);

struct PP_Var
ppb_var_create_object_with_module_deprecated(PP_Module module,
                                             const struct PPP_Class_Deprecated *object_class,
                                             void *object_data);

#endif // FPP__PPB_VAR_H
