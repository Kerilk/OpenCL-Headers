/*******************************************************************************
 * Copyright (c) 2008-2021 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#ifndef OPENCL_CL_EXT_H_
#define OPENCL_CL_EXT_H_

#include <CL/cl.h>

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************
* cl_khr_create_command_queue
***************************************************************/
#define cl_khr_create_command_queue 1
#define CL_KHR_CREATE_COMMAND_QUEUE "cl_khr_create_command_queue"

typedef cl_properties       cl_queue_properties_khr;


extern CL_API_ENTRY cl_command_queue CL_API_CALL
clCreateCommandQueueWithPropertiesKHR(
    cl_context context,
    cl_device_id device,
    const cl_queue_properties_khr* properties,
    cl_int* errcode_ret) CL_API_SUFFIX__VERSION_1_2;

typedef cl_command_queue (CL_API_CALL *
clCreateCommandQueueWithPropertiesKHR_fn)(
    cl_context context,
    cl_device_id device,
    const cl_queue_properties_khr* properties,
    cl_int* errcode_ret) CL_API_SUFFIX__VERSION_1_2;

/***************************************************************
* cl_khr_depth_images
***************************************************************/
#define cl_khr_depth_images 1
#define CL_KHR_DEPTH_IMAGES "cl_khr_depth_images"

#if !defined(CL_VERSION_1_2)
/* cl_channel_order - defined in CL.h for OpenCL 1.2 (?) and newer */
#define CL_DEPTH                                            0x10BD
#endif

/***************************************************************
* cl_khr_device_uuid
***************************************************************/
#define cl_khr_device_uuid 1
#define CL_KHR_DEVICE_UUID "cl_khr_device_uuid"

/* Size Constants */
#define CL_UUID_SIZE_KHR                                    16
#define CL_LUID_SIZE_KHR                                    8

/* cl_device_info */
#define CL_DEVICE_UUID_KHR                                  0x106A
#define CL_DRIVER_UUID_KHR                                  0x106B
#define CL_DEVICE_LUID_VALID_KHR                            0x106C
#define CL_DEVICE_LUID_KHR                                  0x106D
#define CL_DEVICE_NODE_MASK_KHR                             0x106E

/***************************************************************
* cl_khr_extended_versioning
***************************************************************/
#define cl_khr_extended_versioning 1
#define CL_KHR_EXTENDED_VERSIONING "cl_khr_extended_versioning"

#define CL_VERSION_MAJOR_BITS_KHR                           10
#define CL_VERSION_MINOR_BITS_KHR                           10
#define CL_VERSION_PATCH_BITS_KHR                           12

#define CL_VERSION_MAJOR_MASK_KHR ((1 << CL_VERSION_MAJOR_BITS_KHR) - 1)
#define CL_VERSION_MINOR_MASK_KHR ((1 << CL_VERSION_MINOR_BITS_KHR) - 1)
#define CL_VERSION_PATCH_MASK_KHR ((1 << CL_VERSION_PATCH_BITS_KHR) - 1)

#define CL_VERSION_MAJOR_KHR(version) ((version) >> (CL_VERSION_MINOR_BITS_KHR + CL_VERSION_PATCH_BITS_KHR))
#define CL_VERSION_MINOR_KHR(version) (((version) >> CL_VERSION_PATCH_BITS_KHR) & CL_VERSION_MINOR_MASK_KHR)
#define CL_VERSION_PATCH_KHR(version) ((version) & CL_VERSION_PATCH_MASK_KHR)

#define CL_MAKE_VERSION_KHR(major, minor, patch) \
    ((((major) & CL_VERSION_MAJOR_MASK_KHR) << (CL_VERSION_MINOR_BITS_KHR + CL_VERSION_PATCH_BITS_KHR)) | \
    (((minor) &  CL_VERSION_MINOR_MASK_KHR) << CL_VERSION_PATCH_BITS_KHR) | \
    ((patch) & CL_VERSION_PATCH_MASK_KHR))

#define CL_NAME_VERSION_MAX_NAME_SIZE_KHR                   64

typedef cl_uint             cl_version_khr;
typedef struct _cl_name_version_khr {
    cl_version_khr version;
    char name[CL_NAME_VERSION_MAX_NAME_SIZE_KHR];
} cl_name_version_khr;

/* cl_platform_info */
#define CL_PLATFORM_NUMERIC_VERSION_KHR                     0x0906
#define CL_PLATFORM_EXTENSIONS_WITH_VERSION_KHR             0x0907

/* cl_device_info */
#define CL_DEVICE_NUMERIC_VERSION_KHR                       0x105E
#define CL_DEVICE_OPENCL_C_NUMERIC_VERSION_KHR              0x105F
#define CL_DEVICE_EXTENSIONS_WITH_VERSION_KHR               0x1060
#define CL_DEVICE_ILS_WITH_VERSION_KHR                      0x1061
#define CL_DEVICE_BUILT_IN_KERNELS_WITH_VERSION_KHR         0x1062

/***************************************************************
* cl_khr_fp16
***************************************************************/
#define cl_khr_fp16 1
#define CL_KHR_FP16 "cl_khr_fp16"

/* cl_device_info */
#define CL_DEVICE_HALF_FP_CONFIG                            0x1033

/***************************************************************
* cl_khr_fp64
***************************************************************/
#define cl_khr_fp64 1
#define CL_KHR_FP64 "cl_khr_fp64"

#if !defined(CL_VERSION_1_2)
/* cl_device_info - defined in CL.h for OpenCL 1.2 and newer */
#define CL_DEVICE_DOUBLE_FP_CONFIG                          0x1032
#endif

/***************************************************************
* cl_khr_icd
***************************************************************/
#define cl_khr_icd 1
#define CL_KHR_ICD "cl_khr_icd"

/* cl_platform_info */
#define CL_PLATFORM_ICD_SUFFIX_KHR                          0x0920

/* Error codes */
#define CL_PLATFORM_NOT_FOUND_KHR                           -1001


extern CL_API_ENTRY cl_int CL_API_CALL
clIcdGetPlatformIDsKHR(
    cl_uint num_entries,
    cl_platform_id* platforms,
    cl_uint* num_platforms) ;

typedef cl_int (CL_API_CALL *
clIcdGetPlatformIDsKHR_fn)(
    cl_uint num_entries,
    cl_platform_id* platforms,
    cl_uint* num_platforms) ;

/***************************************************************
* cl_khr_il_program
***************************************************************/
#define cl_khr_il_program 1
#define CL_KHR_IL_PROGRAM "cl_khr_il_program"

/* cl_device_info */
#define CL_DEVICE_IL_VERSION_KHR                            0x105B

/* cl_program_info */
#define CL_PROGRAM_IL_KHR                                   0x1169


extern CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithILKHR(
    cl_context context,
    const void* il,
    size_t length,
    cl_int* errcode_ret) ;

typedef cl_program (CL_API_CALL *
clCreateProgramWithILKHR_fn)(
    cl_context context,
    const void* il,
    size_t length,
    cl_int* errcode_ret) ;

/***************************************************************
* cl_khr_image2D_from_buffer
***************************************************************/
#define cl_khr_image2D_from_buffer 1
#define CL_KHR_IMAGE2D_FROM_BUFFER "cl_khr_image2D_from_buffer"

/* cl_device_info */
#define CL_DEVICE_IMAGE_PITCH_ALIGNMENT_KHR                 0x104A
#define CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT_KHR          0x104B

/***************************************************************
* cl_khr_initialize_memory
***************************************************************/
#define cl_khr_initialize_memory 1
#define CL_KHR_INITIALIZE_MEMORY "cl_khr_initialize_memory"

/* Interop tokens */
#define CL_CONTEXT_MEMORY_INITIALIZE_KHR                    0x2030

/***************************************************************
* cl_khr_integer_dot_product
***************************************************************/
#define cl_khr_integer_dot_product 1
#define CL_KHR_INTEGER_DOT_PRODUCT "cl_khr_integer_dot_product"

typedef cl_bitfield         cl_device_integer_dot_product_capabilities_khr;

/* cl_device_integer_dot_product_capabilities_khr */
#define CL_DEVICE_INTEGER_DOT_PRODUCT_INPUT_4x8BIT_PACKED_KHR (1 << 0)
#define CL_DEVICE_INTEGER_DOT_PRODUCT_INPUT_4x8BIT_KHR      (1 << 1)

/* cl_device_info */
#define CL_DEVICE_INTEGER_DOT_PRODUCT_CAPABILITIES_KHR      0x1073

/***************************************************************
* cl_khr_mipmap_image
***************************************************************/
#define cl_khr_mipmap_image 1
#define CL_KHR_MIPMAP_IMAGE "cl_khr_mipmap_image"

/* cl_sampler_properties */
#define CL_SAMPLER_MIP_FILTER_MODE_KHR                      0x1155
#define CL_SAMPLER_LOD_MIN_KHR                              0x1156
#define CL_SAMPLER_LOD_MAX_KHR                              0x1157

/***************************************************************
* cl_khr_pci_bus_info
***************************************************************/
#define cl_khr_pci_bus_info 1
#define CL_KHR_PCI_BUS_INFO "cl_khr_pci_bus_info"

typedef struct _cl_device_pci_bus_info_khr {
    cl_uint pci_domain;
    cl_uint pci_bus;
    cl_uint pci_device;
    cl_uint pci_function;
} cl_device_pci_bus_info_khr;

/* cl_device_info */
#define CL_DEVICE_PCI_BUS_INFO_KHR                          0x410F

/***************************************************************
* cl_khr_priority_hints
***************************************************************/
#define cl_khr_priority_hints 1
#define CL_KHR_PRIORITY_HINTS "cl_khr_priority_hints"

/* To be used by clGetEventInfo */
typedef cl_uint             cl_queue_priority_khr;

/* cl_queue_properties */
#define CL_QUEUE_PRIORITY_KHR                               0x1096

/* cl_queue_priority_khr */
#define CL_QUEUE_PRIORITY_HIGH_KHR                          (1 << 0)
#define CL_QUEUE_PRIORITY_MED_KHR                           (1 << 1)
#define CL_QUEUE_PRIORITY_LOW_KHR                           (1 << 2)

/***************************************************************
* cl_khr_spir
***************************************************************/
#define cl_khr_spir 1
#define CL_KHR_SPIR "cl_khr_spir"

/* cl_device_info */
#define CL_DEVICE_SPIR_VERSIONS                             0x40E0

/* cl_program_binary_type */
#define CL_PROGRAM_BINARY_TYPE_INTERMEDIATE                 0x40E1

/***************************************************************
* cl_khr_subgroup_named_barrier
***************************************************************/
#define cl_khr_subgroup_named_barrier 1
#define CL_KHR_SUBGROUP_NAMED_BARRIER "cl_khr_subgroup_named_barrier"

/* cl_device_info */
#define CL_DEVICE_MAX_NAMED_BARRIER_COUNT_KHR               0x2035

/***************************************************************
* cl_khr_subgroups
***************************************************************/
#define cl_khr_subgroups 1
#define CL_KHR_SUBGROUPS "cl_khr_subgroups"

#if !defined(CL_VERSION_2_1)
/* defined in CL.h for OpenCL 2.1 and newer */
typedef cl_uint             cl_kernel_sub_group_info;
#endif

/* cl_kernel_sub_group_info */
#define CL_KERNEL_MAX_SUB_GROUP_SIZE_FOR_NDRANGE_KHR        0x2033
#define CL_KERNEL_SUB_GROUP_COUNT_FOR_NDRANGE_KHR           0x2034


extern CL_API_ENTRY cl_int CL_API_CALL
clGetKernelSubGroupInfoKHR(
    cl_kernel in_kernel,
    cl_device_id in_device,
    cl_kernel_sub_group_info param_name,
    size_t input_value_size,
    const void* input_value,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret) CL_API_SUFFIX__VERSION_2_0_DEPRECATED;

typedef cl_int (CL_API_CALL *
clGetKernelSubGroupInfoKHR_fn)(
    cl_kernel in_kernel,
    cl_device_id in_device,
    cl_kernel_sub_group_info param_name,
    size_t input_value_size,
    const void* input_value,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret) CL_API_SUFFIX__VERSION_2_0_DEPRECATED;

/***************************************************************
* cl_khr_suggested_local_work_size
***************************************************************/
#define cl_khr_suggested_local_work_size 1
#define CL_KHR_SUGGESTED_LOCAL_WORK_SIZE "cl_khr_suggested_local_work_size"


extern CL_API_ENTRY cl_int CL_API_CALL
clGetKernelSuggestedLocalWorkSizeKHR(
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint work_dim,
    const size_t* global_work_offset,
    const size_t* global_work_size,
    size_t* suggested_local_work_size) CL_API_SUFFIX__VERSION_3_0;

typedef cl_int (CL_API_CALL *
clGetKernelSuggestedLocalWorkSizeKHR_fn)(
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint work_dim,
    const size_t* global_work_offset,
    const size_t* global_work_size,
    size_t* suggested_local_work_size) CL_API_SUFFIX__VERSION_3_0;

/***************************************************************
* cl_khr_terminate_context
***************************************************************/
#define cl_khr_terminate_context 1
#define CL_KHR_TERMINATE_CONTEXT "cl_khr_terminate_context"

/* cl_device_info */
#define CL_DEVICE_TERMINATE_CAPABILITY_KHR                  0x2031

/* cl_context_properties */
#define CL_CONTEXT_TERMINATE_KHR                            0x2032

/* Error codes */
#define CL_CONTEXT_TERMINATED_KHR                           -1121


extern CL_API_ENTRY cl_int CL_API_CALL
clTerminateContextKHR(
    cl_context context) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clTerminateContextKHR_fn)(
    cl_context context) CL_API_SUFFIX__VERSION_1_2;

/***************************************************************
* cl_khr_throttle_hints
***************************************************************/
#define cl_khr_throttle_hints 1
#define CL_KHR_THROTTLE_HINTS "cl_khr_throttle_hints"

/* To be used by clGetEventInfo */
typedef cl_uint             cl_queue_throttle_khr;

/* cl_queue_properties */
#define CL_QUEUE_THROTTLE_KHR                               0x1097

/* cl_queue_throttle_khr */
#define CL_QUEUE_THROTTLE_HIGH_KHR                          (1 << 0)
#define CL_QUEUE_THROTTLE_MED_KHR                           (1 << 1)
#define CL_QUEUE_THROTTLE_LOW_KHR                           (1 << 2)

/***************************************************************
* cl_ext_cxx_for_opencl
***************************************************************/
#define cl_ext_cxx_for_opencl 1
#define CL_EXT_CXX_FOR_OPENCL "cl_ext_cxx_for_opencl"

/* cl_device_info */
#define CL_DEVICE_CXX_FOR_OPENCL_NUMERIC_VERSION_EXT        0x4230

/***************************************************************
* cl_ext_device_fission
***************************************************************/
#define cl_ext_device_fission 1
#define CL_EXT_DEVICE_FISSION "cl_ext_device_fission"

typedef cl_ulong            cl_device_partition_property_ext;

/* Error codes */
#define CL_DEVICE_PARTITION_FAILED_EXT                      -1057
#define CL_INVALID_PARTITION_COUNT_EXT                      -1058
#define CL_INVALID_PARTITION_NAME_EXT                       -1059

/* cl_device_info */
#define CL_DEVICE_PARENT_DEVICE_EXT                         0x4054
#define CL_DEVICE_PARTITION_TYPES_EXT                       0x4055
#define CL_DEVICE_AFFINITY_DOMAINS_EXT                      0x4056
#define CL_DEVICE_REFERENCE_COUNT_EXT                       0x4057
#define CL_DEVICE_PARTITION_STYLE_EXT                       0x4058

/* cl_device_partition_property_ext */
#define CL_DEVICE_PARTITION_EQUALLY_EXT                     0x4050
#define CL_DEVICE_PARTITION_BY_COUNTS_EXT                   0x4051
#define CL_DEVICE_PARTITION_BY_NAMES_EXT                    0x4052
#define CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN_EXT          0x4053

/* cl_device_partition_property_ext - affinity domains */
#define CL_AFFINITY_DOMAIN_L1_CACHE_EXT                     0x1
#define CL_AFFINITY_DOMAIN_L2_CACHE_EXT                     0x2
#define CL_AFFINITY_DOMAIN_L3_CACHE_EXT                     0x3
#define CL_AFFINITY_DOMAIN_L4_CACHE_EXT                     0x4
#define CL_AFFINITY_DOMAIN_NUMA_EXT                         0x10
#define CL_AFFINITY_DOMAIN_NEXT_FISSIONABLE_EXT             0x100

/* cl_device_partition_property_ext - list terminators */
#define CL_PROPERTIES_LIST_END_EXT                          ((cl_device_partition_property_ext)0)
#define CL_PARTITION_BY_COUNTS_LIST_END_EXT                 ((cl_device_partition_property_ext)0)
#define CL_PARTITION_BY_NAMES_LIST_END_EXT                  ((cl_device_partition_property_ext)0 - 1)


extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseDeviceEXT(
    cl_device_id device) CL_API_SUFFIX__VERSION_1_1;

typedef cl_int (CL_API_CALL *
clReleaseDeviceEXT_fn)(
    cl_device_id device) CL_API_SUFFIX__VERSION_1_1;

extern CL_API_ENTRY cl_int CL_API_CALL
clRetainDeviceEXT(
    cl_device_id device) CL_API_SUFFIX__VERSION_1_1;

typedef cl_int (CL_API_CALL *
clRetainDeviceEXT_fn)(
    cl_device_id device) CL_API_SUFFIX__VERSION_1_1;

extern CL_API_ENTRY cl_int CL_API_CALL
clCreateSubDevicesEXT(
    cl_device_id in_device,
    const cl_device_partition_property_ext* properties,
    cl_uint num_entries,
    cl_device_id* out_devices,
    cl_uint* num_devices) CL_API_SUFFIX__VERSION_1_1;

typedef cl_int (CL_API_CALL *
clCreateSubDevicesEXT_fn)(
    cl_device_id in_device,
    const cl_device_partition_property_ext* properties,
    cl_uint num_entries,
    cl_device_id* out_devices,
    cl_uint* num_devices) CL_API_SUFFIX__VERSION_1_1;

/***************************************************************
* cl_ext_migrate_memobject
***************************************************************/
#define cl_ext_migrate_memobject 1
#define CL_EXT_MIGRATE_MEMOBJECT "cl_ext_migrate_memobject"

typedef cl_bitfield         cl_mem_migration_flags_ext;

/* cl_mem_migration_flags_ext */
#define CL_MIGRATE_MEM_OBJECT_HOST_EXT                      (1 << 0)

/* cl_command_type */
#define CL_COMMAND_MIGRATE_MEM_OBJECT_EXT                   0x4040


extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueMigrateMemObjectEXT(
    cl_command_queue command_queue,
    cl_uint num_mem_objects,
    const cl_mem* mem_objects,
    cl_mem_migration_flags_ext flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;

typedef cl_int (CL_API_CALL *
clEnqueueMigrateMemObjectEXT_fn)(
    cl_command_queue command_queue,
    cl_uint num_mem_objects,
    const cl_mem* mem_objects,
    cl_mem_migration_flags_ext flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;

/***************************************************************
* cl_APPLE_ContextLoggingFunctions
***************************************************************/
#define cl_APPLE_ContextLoggingFunctions 1
#define CL_APPLE_CONTEXTLOGGINGFUNCTIONS "cl_APPLE_ContextLoggingFunctions"


extern CL_API_ENTRY void CL_API_CALL
clLogMessagesToSystemLogAPPLE(
    const char* errstr,
    const void* private_info,
    size_t cb,
    void* user_data) CL_API_SUFFIX__VERSION_1_0;

typedef void (CL_API_CALL *
clLogMessagesToSystemLogAPPLE_fn)(
    const char* errstr,
    const void* private_info,
    size_t cb,
    void* user_data) CL_API_SUFFIX__VERSION_1_0;

extern CL_API_ENTRY void CL_API_CALL
clLogMessagesToStdoutAPPLE(
    const char* errstr,
    const void* private_info,
    size_t cb,
    void* user_data) CL_API_SUFFIX__VERSION_1_0;

typedef void (CL_API_CALL *
clLogMessagesToStdoutAPPLE_fn)(
    const char* errstr,
    const void* private_info,
    size_t cb,
    void* user_data) CL_API_SUFFIX__VERSION_1_0;

extern CL_API_ENTRY void CL_API_CALL
clLogMessagesToStderrAPPLE(
    const char* errstr,
    const void* private_info,
    size_t cb,
    void* user_data) CL_API_SUFFIX__VERSION_1_0;

typedef void (CL_API_CALL *
clLogMessagesToStderrAPPLE_fn)(
    const char* errstr,
    const void* private_info,
    size_t cb,
    void* user_data) CL_API_SUFFIX__VERSION_1_0;

/***************************************************************
* cl_APPLE_SetMemObjectDestructor
***************************************************************/
#define cl_APPLE_SetMemObjectDestructor 1
#define CL_APPLE_SETMEMOBJECTDESTRUCTOR "cl_APPLE_SetMemObjectDestructor"


extern CL_API_ENTRY cl_int CL_API_CALL
clSetMemObjectDestructorAPPLE(
    cl_mem memobj,
    void (CL_CALLBACK* pfn_notify)(cl_mem memobj, void* user_data),
    void* user_data) CL_API_SUFFIX__VERSION_1_0;

typedef cl_int (CL_API_CALL *
clSetMemObjectDestructorAPPLE_fn)(
    cl_mem memobj,
    void (CL_CALLBACK* pfn_notify)(cl_mem memobj, void* user_data),
    void* user_data) CL_API_SUFFIX__VERSION_1_0;

/***************************************************************
* cl_amd_device_attribute_query
***************************************************************/
#define cl_amd_device_attribute_query 1
#define CL_AMD_DEVICE_ATTRIBUTE_QUERY "cl_amd_device_attribute_query"

/* cl_device_info */
#define CL_DEVICE_PROFILING_TIMER_OFFSET_AMD                0x4036
#define CL_DEVICE_TOPOLOGY_AMD                              0x4037
#define CL_DEVICE_BOARD_NAME_AMD                            0x4038
#define CL_DEVICE_GLOBAL_FREE_MEMORY_AMD                    0x4039
#define CL_DEVICE_SIMD_PER_COMPUTE_UNIT_AMD                 0x4040
#define CL_DEVICE_SIMD_WIDTH_AMD                            0x4041
#define CL_DEVICE_SIMD_INSTRUCTION_WIDTH_AMD                0x4042
#define CL_DEVICE_WAVEFRONT_WIDTH_AMD                       0x4043
#define CL_DEVICE_GLOBAL_MEM_CHANNELS_AMD                   0x4044
#define CL_DEVICE_GLOBAL_MEM_CHANNEL_BANKS_AMD              0x4045
#define CL_DEVICE_GLOBAL_MEM_CHANNEL_BANK_WIDTH_AMD         0x4046
#define CL_DEVICE_LOCAL_MEM_SIZE_PER_COMPUTE_UNIT_AMD       0x4047
#define CL_DEVICE_LOCAL_MEM_BANKS_AMD                       0x4048
#define CL_DEVICE_THREAD_TRACE_SUPPORTED_AMD                0x4049
#define CL_DEVICE_GFXIP_MAJOR_AMD                           0x404A
#define CL_DEVICE_GFXIP_MINOR_AMD                           0x404B
#define CL_DEVICE_AVAILABLE_ASYNC_QUEUES_AMD                0x404C
#define CL_DEVICE_PREFERRED_WORK_GROUP_SIZE_AMD             0x4030
#define CL_DEVICE_MAX_WORK_GROUP_SIZE_AMD                   0x4031
#define CL_DEVICE_PREFERRED_CONSTANT_BUFFER_SIZE_AMD        0x4033
#define CL_DEVICE_PCIE_ID_AMD                               0x4034

/***************************************************************
* cl_arm_controlled_kernel_termination
***************************************************************/
#define cl_arm_controlled_kernel_termination 1
#define CL_ARM_CONTROLLED_KERNEL_TERMINATION "cl_arm_controlled_kernel_termination"

/* Types */
typedef cl_bitfield         cl_device_controlled_termination_capabilities_arm;

/* Error codes */
#define CL_COMMAND_TERMINATED_ITSELF_WITH_FAILURE_ARM       -1108

/* cl_device_controlled_termination_capabilities_arm */
#define CL_DEVICE_CONTROLLED_TERMINATION_SUCCESS_ARM        (1 << 0)
#define CL_DEVICE_CONTROLLED_TERMINATION_FAILURE_ARM        (1 << 1)
#define CL_DEVICE_CONTROLLED_TERMINATION_QUERY_ARM          (1 << 2)

/* cl_device_info */
#define CL_DEVICE_CONTROLLED_TERMINATION_CAPABILITIES_ARM   0x41EE

/* cl_event_info */
#define CL_EVENT_COMMAND_TERMINATION_REASON_ARM             0x41ED

/* cl_command_termination_reason_arm */
#define CL_COMMAND_TERMINATION_COMPLETION_ARM               0
#define CL_COMMAND_TERMINATION_CONTROLLED_SUCCESS_ARM       1
#define CL_COMMAND_TERMINATION_CONTROLLED_FAILURE_ARM       2
#define CL_COMMAND_TERMINATION_ERROR_ARM                    3

/***************************************************************
* cl_arm_get_core_id
***************************************************************/
#define cl_arm_get_core_id 1
#define CL_ARM_GET_CORE_ID "cl_arm_get_core_id"

/* cl_device_info */
#define CL_DEVICE_COMPUTE_UNITS_BITFIELD_ARM                0x40BF

/***************************************************************
* cl_arm_import_memory
***************************************************************/
#define cl_arm_import_memory 1
#define CL_ARM_IMPORT_MEMORY "cl_arm_import_memory"

typedef intptr_t            cl_import_properties_arm;

/* cl_import_properties_arm */
#define CL_IMPORT_TYPE_ARM                                  0x40B2
#define CL_IMPORT_TYPE_HOST_ARM                             0x40B3
#define CL_IMPORT_TYPE_DMA_BUF_ARM                          0x40B4
#define CL_IMPORT_TYPE_PROTECTED_ARM                        0x40B5
#define CL_IMPORT_TYPE_ANDROID_HARDWARE_BUFFER_ARM          0x41E2
#define CL_IMPORT_DMA_BUF_DATA_CONSISTENCY_WITH_HOST_ARM    0x41E3
#define CL_IMPORT_MEMORY_WHOLE_ALLOCATION_ARM               SIZE_MAX
#define CL_IMPORT_ANDROID_HARDWARE_BUFFER_PLANE_INDEX_ARM   0x41EF
#define CL_IMPORT_ANDROID_HARDWARE_BUFFER_LAYER_INDEX_ARM   0x41F0


extern CL_API_ENTRY cl_mem CL_API_CALL
clImportMemoryARM(
    cl_context context,
    cl_mem_flags flags,
    const cl_import_properties_arm* properties,
    void* memory,
    size_t size,
    cl_int* errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef cl_mem (CL_API_CALL *
clImportMemoryARM_fn)(
    cl_context context,
    cl_mem_flags flags,
    const cl_import_properties_arm* properties,
    void* memory,
    size_t size,
    cl_int* errcode_ret) CL_API_SUFFIX__VERSION_1_0;

/***************************************************************
* cl_arm_printf
***************************************************************/
#define cl_arm_printf 1
#define CL_ARM_PRINTF "cl_arm_printf"

/* cl_context_properties */
#define CL_PRINTF_CALLBACK_ARM                              0x40B0
#define CL_PRINTF_BUFFERSIZE_ARM                            0x40B1

/***************************************************************
* cl_arm_scheduling_controls
***************************************************************/
#define cl_arm_scheduling_controls 1
#define CL_ARM_SCHEDULING_CONTROLS "cl_arm_scheduling_controls"

/* Types */
typedef cl_bitfield         cl_device_scheduling_controls_capabilities_arm;

/* cl_device_scheduling_controls_capabilities_arm */
#define CL_DEVICE_SCHEDULING_KERNEL_BATCHING_ARM            (1 << 0)
#define CL_DEVICE_SCHEDULING_WORKGROUP_BATCH_SIZE_ARM       (1 << 1)
#define CL_DEVICE_SCHEDULING_WORKGROUP_BATCH_SIZE_MODIFIER_ARM (1 << 2)
#define CL_DEVICE_SCHEDULING_DEFERRED_FLUSH_ARM             (1 << 3)
#define CL_DEVICE_SCHEDULING_REGISTER_ALLOCATION_ARM        (1 << 4)

/* cl_device_info */
#define CL_DEVICE_SCHEDULING_CONTROLS_CAPABILITIES_ARM      0x41E4
#define CL_DEVICE_SUPPORTED_REGISTER_ALLOCATIONS_ARM        0x41EB

/* cl_kernel_exec_info */
#define CL_KERNEL_EXEC_INFO_WORKGROUP_BATCH_SIZE_ARM        0x41E5
#define CL_KERNEL_EXEC_INFO_WORKGROUP_BATCH_SIZE_MODIFIER_ARM 0x41E6

/* cl_queue_properties */
#define CL_QUEUE_KERNEL_BATCHING_ARM                        0x41E7
#define CL_QUEUE_DEFERRED_FLUSH_ARM                         0x41EC

/***************************************************************
* cl_arm_shared_virtual_memory
***************************************************************/
#define cl_arm_shared_virtual_memory 1
#define CL_ARM_SHARED_VIRTUAL_MEMORY "cl_arm_shared_virtual_memory"

typedef cl_bitfield         cl_svm_mem_flags_arm;
typedef cl_uint             cl_kernel_exec_info_arm;
typedef cl_bitfield         cl_device_svm_capabilities_arm;

/* cl_device_info */
#define CL_DEVICE_SVM_CAPABILITIES_ARM                      0x40B6

/* cl_mem_info */
#define CL_MEM_USES_SVM_POINTER_ARM                         0x40B7

/* cl_kernel_exec_info_arm */
#define CL_KERNEL_EXEC_INFO_SVM_PTRS_ARM                    0x40B8
#define CL_KERNEL_EXEC_INFO_SVM_FINE_GRAIN_SYSTEM_ARM       0x40B9

/* cl_command_type */
#define CL_COMMAND_SVM_FREE_ARM                             0x40BA
#define CL_COMMAND_SVM_MEMCPY_ARM                           0x40BB
#define CL_COMMAND_SVM_MEMFILL_ARM                          0x40BC
#define CL_COMMAND_SVM_MAP_ARM                              0x40BD
#define CL_COMMAND_SVM_UNMAP_ARM                            0x40BE

/* cl_device_svm_capabilities_arm */
#define CL_DEVICE_SVM_COARSE_GRAIN_BUFFER_ARM               (1 << 0)
#define CL_DEVICE_SVM_FINE_GRAIN_BUFFER_ARM                 (1 << 1)
#define CL_DEVICE_SVM_FINE_GRAIN_SYSTEM_ARM                 (1 << 2)
#define CL_DEVICE_SVM_ATOMICS_ARM                           (1 << 3)

/* cl_svm_mem_flags_arm */
#define CL_MEM_SVM_FINE_GRAIN_BUFFER_ARM                    (1 << 10)
#define CL_MEM_SVM_ATOMICS_ARM                              (1 << 11)


extern CL_API_ENTRY void* CL_API_CALL
clSVMAllocARM(
    cl_context context,
    cl_svm_mem_flags_arm flags,
    size_t size,
    cl_uint alignment) CL_API_SUFFIX__VERSION_1_2;

typedef void* (CL_API_CALL *
clSVMAllocARM_fn)(
    cl_context context,
    cl_svm_mem_flags_arm flags,
    size_t size,
    cl_uint alignment) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY void CL_API_CALL
clSVMFreeARM(
    cl_context context,
    void* svm_pointer) CL_API_SUFFIX__VERSION_1_2;

typedef void (CL_API_CALL *
clSVMFreeARM_fn)(
    cl_context context,
    void* svm_pointer) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMFreeARM(
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    void* svm_pointers[],
    void (CL_CALLBACK* pfn_free_func)(cl_command_queue queue, cl_uint num_svm_pointers, void * svm_pointers[], void *user_data),
    void* user_data,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clEnqueueSVMFreeARM_fn)(
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    void* svm_pointers[],
    void (CL_CALLBACK* pfn_free_func)(cl_command_queue queue, cl_uint num_svm_pointers, void * svm_pointers[], void *user_data),
    void* user_data,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMMemcpyARM(
    cl_command_queue command_queue,
    cl_bool blocking_copy,
    void* dst_ptr,
    const void* src_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clEnqueueSVMMemcpyARM_fn)(
    cl_command_queue command_queue,
    cl_bool blocking_copy,
    void* dst_ptr,
    const void* src_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMMemFillARM(
    cl_command_queue command_queue,
    void* svm_ptr,
    const void* pattern,
    size_t pattern_size,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clEnqueueSVMMemFillARM_fn)(
    cl_command_queue command_queue,
    void* svm_ptr,
    const void* pattern,
    size_t pattern_size,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMMapARM(
    cl_command_queue command_queue,
    cl_bool blocking_map,
    cl_map_flags flags,
    void* svm_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clEnqueueSVMMapARM_fn)(
    cl_command_queue command_queue,
    cl_bool blocking_map,
    cl_map_flags flags,
    void* svm_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMUnmapARM(
    cl_command_queue command_queue,
    void* svm_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clEnqueueSVMUnmapARM_fn)(
    cl_command_queue command_queue,
    void* svm_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clSetKernelArgSVMPointerARM(
    cl_kernel kernel,
    cl_uint arg_index,
    const void* arg_value) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clSetKernelArgSVMPointerARM_fn)(
    cl_kernel kernel,
    cl_uint arg_index,
    const void* arg_value) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clSetKernelExecInfoARM(
    cl_kernel kernel,
    cl_kernel_exec_info_arm param_name,
    size_t param_value_size,
    const void* param_value) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clSetKernelExecInfoARM_fn)(
    cl_kernel kernel,
    cl_kernel_exec_info_arm param_name,
    size_t param_value_size,
    const void* param_value) CL_API_SUFFIX__VERSION_1_2;

/***************************************************************
* cl_img_cached_allocations
***************************************************************/
#define cl_img_cached_allocations 1
#define CL_IMG_CACHED_ALLOCATIONS "cl_img_cached_allocations"

/* cl_mem_flags */
#define CL_MEM_USE_UNCACHED_CPU_MEMORY_IMG                  (1 << 26)
#define CL_MEM_USE_CACHED_CPU_MEMORY_IMG                    (1 << 27)

/***************************************************************
* cl_img_generate_mipmap
***************************************************************/
#define cl_img_generate_mipmap 1
#define CL_IMG_GENERATE_MIPMAP "cl_img_generate_mipmap"

typedef cl_uint             cl_mipmap_filter_mode_img;

/* cl_mipmap_filter_mode_img */
#define CL_MIPMAP_FILTER_ANY_IMG                            0x0
#define CL_MIPMAP_FILTER_BOX_IMG                            0x1

/* cl_command_type */
#define CL_COMMAND_GENERATE_MIPMAP_IMG                      0x40D6


extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueGenerateMipmapIMG(
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_image,
    cl_mipmap_filter_mode_img mipmap_filter_mode,
    const size_t* array_region,
    const size_t* mip_region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clEnqueueGenerateMipmapIMG_fn)(
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_image,
    cl_mipmap_filter_mode_img mipmap_filter_mode,
    const size_t* array_region,
    const size_t* mip_region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

/***************************************************************
* cl_img_mem_properties
***************************************************************/
#define cl_img_mem_properties 1
#define CL_IMG_MEM_PROPERTIES "cl_img_mem_properties"

/* cl_mem_properties */
#define CL_MEM_ALLOC_FLAGS_IMG                              0x40D7

/* cl_mem_alloc_flags_img */
#define CL_MEM_ALLOC_RELAX_REQUIREMENTS_IMG                 (1 << 0)

/***************************************************************
* cl_img_use_gralloc_ptr
***************************************************************/
#define cl_img_use_gralloc_ptr 1
#define CL_IMG_USE_GRALLOC_PTR "cl_img_use_gralloc_ptr"

/* Error codes */
#define CL_GRALLOC_RESOURCE_NOT_ACQUIRED_IMG                0x40D4
#define CL_INVALID_GRALLOC_OBJECT_IMG                       0x40D5

/* cl_mem_flags */
#define CL_MEM_USE_GRALLOC_PTR_IMG                          (1 << 28)

/* cl_command_type */
#define CL_COMMAND_ACQUIRE_GRALLOC_OBJECTS_IMG              0x40D2
#define CL_COMMAND_RELEASE_GRALLOC_OBJECTS_IMG              0x40D3


extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueAcquireGrallocObjectsIMG(
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clEnqueueAcquireGrallocObjectsIMG_fn)(
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueReleaseGrallocObjectsIMG(
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clEnqueueReleaseGrallocObjectsIMG_fn)(
    cl_command_queue command_queue,
    cl_uint num_objects,
    const cl_mem* mem_objects,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) CL_API_SUFFIX__VERSION_1_2;

/***************************************************************
* cl_img_yuv_image
***************************************************************/
#define cl_img_yuv_image 1
#define CL_IMG_YUV_IMAGE "cl_img_yuv_image"

/* cl_channel_order */
#define CL_NV21_IMG                                         0x40D0
#define CL_YV12_IMG                                         0x40D1

/***************************************************************
* cl_intel_accelerator
***************************************************************/
#define cl_intel_accelerator 1
#define CL_INTEL_ACCELERATOR "cl_intel_accelerator"

typedef struct _cl_accelerator_intel* cl_accelerator_intel;
typedef cl_uint             cl_accelerator_type_intel;
typedef cl_uint             cl_accelerator_info_intel;

/* cl_accelerator_info_intel */
#define CL_ACCELERATOR_DESCRIPTOR_INTEL                     0x4090
#define CL_ACCELERATOR_REFERENCE_COUNT_INTEL                0x4091
#define CL_ACCELERATOR_CONTEXT_INTEL                        0x4092
#define CL_ACCELERATOR_TYPE_INTEL                           0x4093

/* Error codes */
#define CL_INVALID_ACCELERATOR_INTEL                        -1094
#define CL_INVALID_ACCELERATOR_TYPE_INTEL                   -1095
#define CL_INVALID_ACCELERATOR_DESCRIPTOR_INTEL             -1096
#define CL_ACCELERATOR_TYPE_NOT_SUPPORTED_INTEL             -1097


extern CL_API_ENTRY cl_accelerator_intel CL_API_CALL
clCreateAcceleratorINTEL(
    cl_context context,
    cl_accelerator_type_intel accelerator_type,
    size_t descriptor_size,
    const void* descriptor,
    cl_int* errcode_ret) CL_API_SUFFIX__VERSION_1_2;

typedef cl_accelerator_intel (CL_API_CALL *
clCreateAcceleratorINTEL_fn)(
    cl_context context,
    cl_accelerator_type_intel accelerator_type,
    size_t descriptor_size,
    const void* descriptor,
    cl_int* errcode_ret) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clGetAcceleratorInfoINTEL(
    cl_accelerator_intel accelerator,
    cl_accelerator_info_intel param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clGetAcceleratorInfoINTEL_fn)(
    cl_accelerator_intel accelerator,
    cl_accelerator_info_intel param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clRetainAcceleratorINTEL(
    cl_accelerator_intel accelerator) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clRetainAcceleratorINTEL_fn)(
    cl_accelerator_intel accelerator) CL_API_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseAcceleratorINTEL(
    cl_accelerator_intel accelerator) CL_API_SUFFIX__VERSION_1_2;

typedef cl_int (CL_API_CALL *
clReleaseAcceleratorINTEL_fn)(
    cl_accelerator_intel accelerator) CL_API_SUFFIX__VERSION_1_2;

/***************************************************************
* cl_intel_advanced_motion_estimation
***************************************************************/
#define cl_intel_advanced_motion_estimation 1
#define CL_INTEL_ADVANCED_MOTION_ESTIMATION "cl_intel_advanced_motion_estimation"

/* cl_device_info */
#define CL_DEVICE_ME_VERSION_INTEL                          0x407E

#define CL_ME_VERSION_LEGACY_INTEL                          0x0
#define CL_ME_VERSION_ADVANCED_VER_1_INTEL                  0x1
#define CL_ME_VERSION_ADVANCED_VER_2_INTEL                  0x2

#define CL_ME_CHROMA_INTRA_PREDICT_ENABLED_INTEL            0x1
#define CL_ME_LUMA_INTRA_PREDICT_ENABLED_INTEL              0x2

#define CL_ME_SKIP_BLOCK_TYPE_16x16_INTEL                   0x0
#define CL_ME_SKIP_BLOCK_TYPE_8x8_INTEL                     0x1

#define CL_ME_COST_PENALTY_NONE_INTEL                       0x0
#define CL_ME_COST_PENALTY_LOW_INTEL                        0x1
#define CL_ME_COST_PENALTY_NORMAL_INTEL                     0x2
#define CL_ME_COST_PENALTY_HIGH_INTEL                       0x3

#define CL_ME_COST_PRECISION_QPEL_INTEL                     0x0
#define CL_ME_COST_PRECISION_HPEL_INTEL                     0x1
#define CL_ME_COST_PRECISION_PEL_INTEL                      0x2
#define CL_ME_COST_PRECISION_DPEL_INTEL                     0x3

#define CL_ME_LUMA_PREDICTOR_MODE_VERTICAL_INTEL            0x0
#define CL_ME_LUMA_PREDICTOR_MODE_HORIZONTAL_INTEL          0x1
#define CL_ME_LUMA_PREDICTOR_MODE_DC_INTEL                  0x2
#define CL_ME_LUMA_PREDICTOR_MODE_DIAGONAL_DOWN_LEFT_INTEL  0x3
#define CL_ME_LUMA_PREDICTOR_MODE_DIAGONAL_DOWN_RIGHT_INTEL 0x4
#define CL_ME_LUMA_PREDICTOR_MODE_PLANE_INTEL               0x4
#define CL_ME_LUMA_PREDICTOR_MODE_VERTICAL_RIGHT_INTEL      0x5
#define CL_ME_LUMA_PREDICTOR_MODE_HORIZONTAL_DOWN_INTEL     0x6
#define CL_ME_LUMA_PREDICTOR_MODE_VERTICAL_LEFT_INTEL       0x7
#define CL_ME_LUMA_PREDICTOR_MODE_HORIZONTAL_UP_INTEL       0x8

#define CL_ME_CHROMA_PREDICTOR_MODE_DC_INTEL                0x0
#define CL_ME_CHROMA_PREDICTOR_MODE_HORIZONTAL_INTEL        0x1
#define CL_ME_CHROMA_PREDICTOR_MODE_VERTICAL_INTEL          0x2
#define CL_ME_CHROMA_PREDICTOR_MODE_PLANE_INTEL             0x3

#define CL_ME_FORWARD_INPUT_MODE_INTEL                      0x1
#define CL_ME_BACKWARD_INPUT_MODE_INTEL                     0x2
#define CL_ME_BIDIRECTION_INPUT_MODE_INTEL                  0x3

#define CL_ME_BIDIR_WEIGHT_QUARTER_INTEL                    16
#define CL_ME_BIDIR_WEIGHT_THIRD_INTEL                      21
#define CL_ME_BIDIR_WEIGHT_HALF_INTEL                       32
#define CL_ME_BIDIR_WEIGHT_TWO_THIRD_INTEL                  43
#define CL_ME_BIDIR_WEIGHT_THREE_QUARTER_INTEL              48

/***************************************************************
* cl_intel_command_queue_families
***************************************************************/
#define cl_intel_command_queue_families 1
#define CL_INTEL_COMMAND_QUEUE_FAMILIES "cl_intel_command_queue_families"

typedef cl_bitfield         cl_command_queue_capabilities_intel;

#define CL_QUEUE_FAMILY_MAX_NAME_SIZE_INTEL                 64

typedef struct _cl_queue_family_properties_intel {
    cl_command_queue_properties properties;
    cl_command_queue_capabilities_intel capabilities;
    cl_uint count;
    char name[CL_QUEUE_FAMILY_MAX_NAME_SIZE_INTEL];
} cl_queue_family_properties_intel;

/* cl_device_info */
#define CL_DEVICE_QUEUE_FAMILY_PROPERTIES_INTEL             0x418B

/* cl_queue_properties */
#define CL_QUEUE_FAMILY_INTEL                               0x418C
#define CL_QUEUE_INDEX_INTEL                                0x418D

/* cl_command_queue_capabilities_intel */
#define CL_QUEUE_DEFAULT_CAPABILITIES_INTEL                 0
#define CL_QUEUE_CAPABILITY_CREATE_SINGLE_QUEUE_EVENTS_INTEL (1 << 0)
#define CL_QUEUE_CAPABILITY_CREATE_CROSS_QUEUE_EVENTS_INTEL (1 << 1)
#define CL_QUEUE_CAPABILITY_SINGLE_QUEUE_EVENT_WAIT_LIST_INTEL (1 << 2)
#define CL_QUEUE_CAPABILITY_CROSS_QUEUE_EVENT_WAIT_LIST_INTEL (1 << 3)
#define CL_QUEUE_CAPABILITY_TRANSFER_BUFFER_INTEL           (1 << 8)
#define CL_QUEUE_CAPABILITY_TRANSFER_BUFFER_RECT_INTEL      (1 << 9)
#define CL_QUEUE_CAPABILITY_MAP_BUFFER_INTEL                (1 << 10)
#define CL_QUEUE_CAPABILITY_FILL_BUFFER_INTEL               (1 << 11)
#define CL_QUEUE_CAPABILITY_TRANSFER_IMAGE_INTEL            (1 << 12)
#define CL_QUEUE_CAPABILITY_MAP_IMAGE_INTEL                 (1 << 13)
#define CL_QUEUE_CAPABILITY_FILL_IMAGE_INTEL                (1 << 14)
#define CL_QUEUE_CAPABILITY_TRANSFER_BUFFER_IMAGE_INTEL     (1 << 15)
#define CL_QUEUE_CAPABILITY_TRANSFER_IMAGE_BUFFER_INTEL     (1 << 16)
#define CL_QUEUE_CAPABILITY_MARKER_INTEL                    (1 << 24)
#define CL_QUEUE_CAPABILITY_BARRIER_INTEL                   (1 << 25)
#define CL_QUEUE_CAPABILITY_KERNEL_INTEL                    (1 << 26)

/***************************************************************
* cl_intel_create_buffer_with_properties
***************************************************************/
#define cl_intel_create_buffer_with_properties 1
#define CL_INTEL_CREATE_BUFFER_WITH_PROPERTIES "cl_intel_create_buffer_with_properties"

typedef cl_properties       cl_mem_properties_intel;


extern CL_API_ENTRY cl_mem CL_API_CALL
clCreateBufferWithPropertiesINTEL(
    cl_context context,
    const cl_mem_properties_intel* properties,
    cl_mem_flags flags,
    size_t size,
    void* host_ptr,
    cl_int* errcode_ret) ;

typedef cl_mem (CL_API_CALL *
clCreateBufferWithPropertiesINTEL_fn)(
    cl_context context,
    const cl_mem_properties_intel* properties,
    cl_mem_flags flags,
    size_t size,
    void* host_ptr,
    cl_int* errcode_ret) ;

/***************************************************************
* cl_intel_device_partition_by_names
***************************************************************/
#define cl_intel_device_partition_by_names 1
#define CL_INTEL_DEVICE_PARTITION_BY_NAMES "cl_intel_device_partition_by_names"

#define CL_DEVICE_PARTITION_BY_NAMES_INTEL                  0x4052
#define CL_PARTITION_BY_NAMES_LIST_END_INTEL                -1

/***************************************************************
* cl_intel_device_side_avc_motion_estimation
***************************************************************/
#define cl_intel_device_side_avc_motion_estimation 1
#define CL_INTEL_DEVICE_SIDE_AVC_MOTION_ESTIMATION "cl_intel_device_side_avc_motion_estimation"

/* cl_device_info */
#define CL_DEVICE_AVC_ME_VERSION_INTEL                      0x410B
#define CL_DEVICE_AVC_ME_SUPPORTS_TEXTURE_SAMPLER_USE_INTEL 0x410C
#define CL_DEVICE_AVC_ME_SUPPORTS_PREEMPTION_INTEL          0x410D

/* returned by CL_DEVICE_AVC_ME_VERSION_INTEL */
#define CL_AVC_ME_VERSION_0_INTEL                           0x0
#define CL_AVC_ME_VERSION_1_INTEL                           0x1

/* Inter macro-block major shape values */
#define CL_AVC_ME_MAJOR_16x16_INTEL                         0x0
#define CL_AVC_ME_MAJOR_16x8_INTEL                          0x1
#define CL_AVC_ME_MAJOR_8x16_INTEL                          0x2
#define CL_AVC_ME_MAJOR_8x8_INTEL                           0x3

/* Inter macro-block minor shape values */
#define CL_AVC_ME_MINOR_8x8_INTEL                           0x0
#define CL_AVC_ME_MINOR_8x4_INTEL                           0x1
#define CL_AVC_ME_MINOR_4x8_INTEL                           0x2
#define CL_AVC_ME_MINOR_4x4_INTEL                           0x3

/* Inter macro-block major direction values */
#define CL_AVC_ME_MAJOR_FORWARD_INTEL                       0x0
#define CL_AVC_ME_MAJOR_BACKWARD_INTEL                      0x1
#define CL_AVC_ME_MAJOR_BIDIRECTIONAL_INTEL                 0x2

/* Inter (IME) partition mask values */
#define CL_AVC_ME_PARTITION_MASK_ALL_INTEL                  0x0
#define CL_AVC_ME_PARTITION_MASK_16x16_INTEL                0x7E
#define CL_AVC_ME_PARTITION_MASK_16x8_INTEL                 0x7D
#define CL_AVC_ME_PARTITION_MASK_8x16_INTEL                 0x7B
#define CL_AVC_ME_PARTITION_MASK_8x8_INTEL                  0x77
#define CL_AVC_ME_PARTITION_MASK_8x4_INTEL                  0x6F
#define CL_AVC_ME_PARTITION_MASK_4x8_INTEL                  0x5F
#define CL_AVC_ME_PARTITION_MASK_4x4_INTEL                  0x3F

/* Search window configuration */
#define CL_AVC_ME_SEARCH_WINDOW_EXHAUSTIVE_INTEL            0x0
#define CL_AVC_ME_SEARCH_WINDOW_SMALL_INTEL                 0x1
#define CL_AVC_ME_SEARCH_WINDOW_TINY_INTEL                  0x2
#define CL_AVC_ME_SEARCH_WINDOW_EXTRA_TINY_INTEL            0x3
#define CL_AVC_ME_SEARCH_WINDOW_DIAMOND_INTEL               0x4
#define CL_AVC_ME_SEARCH_WINDOW_LARGE_DIAMOND_INTEL         0x5
#define CL_AVC_ME_SEARCH_WINDOW_RESERVED0_INTEL             0x6
#define CL_AVC_ME_SEARCH_WINDOW_RESERVED1_INTEL             0x7
#define CL_AVC_ME_SEARCH_WINDOW_CUSTOM_INTEL                0x8
#define CL_AVC_ME_SEARCH_WINDOW_16x12_RADIUS_INTEL          0x9
#define CL_AVC_ME_SEARCH_WINDOW_4x4_RADIUS_INTEL            0x2
#define CL_AVC_ME_SEARCH_WINDOW_2x2_RADIUS_INTEL            0xa

/* SAD adjustment mode */
#define CL_AVC_ME_SAD_ADJUST_MODE_NONE_INTEL                0x0
#define CL_AVC_ME_SAD_ADJUST_MODE_HAAR_INTEL                0x2

/* Pixel resolution */
#define CL_AVC_ME_SUBPIXEL_MODE_INTEGER_INTEL               0x0
#define CL_AVC_ME_SUBPIXEL_MODE_HPEL_INTEL                  0x1
#define CL_AVC_ME_SUBPIXEL_MODE_QPEL_INTEL                  0x3

/* Cost precision values */
#define CL_AVC_ME_COST_PRECISION_QPEL_INTEL                 0x0
#define CL_AVC_ME_COST_PRECISION_HPEL_INTEL                 0x1
#define CL_AVC_ME_COST_PRECISION_PEL_INTEL                  0x2
#define CL_AVC_ME_COST_PRECISION_DPEL_INTEL                 0x3

/* Inter bidirectional weights */
#define CL_AVC_ME_BIDIR_WEIGHT_QUARTER_INTEL                0x10
#define CL_AVC_ME_BIDIR_WEIGHT_THIRD_INTEL                  0x15
#define CL_AVC_ME_BIDIR_WEIGHT_HALF_INTEL                   0x20
#define CL_AVC_ME_BIDIR_WEIGHT_TWO_THIRD_INTEL              0x2B
#define CL_AVC_ME_BIDIR_WEIGHT_THREE_QUARTER_INTEL          0x30

/* Inter border reached values */
#define CL_AVC_ME_BORDER_REACHED_LEFT_INTEL                 0x0
#define CL_AVC_ME_BORDER_REACHED_RIGHT_INTEL                0x2
#define CL_AVC_ME_BORDER_REACHED_TOP_INTEL                  0x4
#define CL_AVC_ME_BORDER_REACHED_BOTTOM_INTEL               0x8

/* Inter skip block partition type */
#define CL_AVC_ME_SKIP_BLOCK_PARTITION_16x16_INTEL          0x0
#define CL_AVC_ME_SKIP_BLOCK_PARTITION_8x8_INTEL            0x4000

/* Inter skip motion vector mask */
#define CL_AVC_ME_SKIP_BLOCK_16x16_FORWARD_ENABLE_INTEL     (0x1 << 24)
#define CL_AVC_ME_SKIP_BLOCK_16x16_BACKWARD_ENABLE_INTEL    (0x2 << 24)
#define CL_AVC_ME_SKIP_BLOCK_16x16_DUAL_ENABLE_INTEL        (0x3 << 24)
#define CL_AVC_ME_SKIP_BLOCK_8x8_FORWARD_ENABLE_INTEL       (0x55 << 24)
#define CL_AVC_ME_SKIP_BLOCK_8x8_BACKWARD_ENABLE_INTEL      (0xAA << 24)
#define CL_AVC_ME_SKIP_BLOCK_8x8_DUAL_ENABLE_INTEL          (0xFF << 24)
#define CL_AVC_ME_SKIP_BLOCK_8x8_0_FORWARD_ENABLE_INTEL     (0x1 << 24)
#define CL_AVC_ME_SKIP_BLOCK_8x8_0_BACKWARD_ENABLE_INTEL    (0x2 << 24)
#define CL_AVC_ME_SKIP_BLOCK_8x8_1_FORWARD_ENABLE_INTEL     (0x1 << 26)
#define CL_AVC_ME_SKIP_BLOCK_8x8_1_BACKWARD_ENABLE_INTEL    (0x2 << 26)
#define CL_AVC_ME_SKIP_BLOCK_8x8_2_FORWARD_ENABLE_INTEL     (0x1 << 28)
#define CL_AVC_ME_SKIP_BLOCK_8x8_2_BACKWARD_ENABLE_INTEL    (0x2 << 28)
#define CL_AVC_ME_SKIP_BLOCK_8x8_3_FORWARD_ENABLE_INTEL     (0x1 << 30)
#define CL_AVC_ME_SKIP_BLOCK_8x8_3_BACKWARD_ENABLE_INTEL    (0x2 << 30)

/* Block based skip type values */
#define CL_AVC_ME_BLOCK_BASED_SKIP_4x4_INTEL                0x00
#define CL_AVC_ME_BLOCK_BASED_SKIP_8x8_INTEL                0x80

/* cl_intel_device_side_avc_motion_estimation.?? */
#define CL_AVC_ME_INTRA_16x16_INTEL                         0x0
#define CL_AVC_ME_INTRA_8x8_INTEL                           0x1
#define CL_AVC_ME_INTRA_4x4_INTEL                           0x2

/* Luma intra partition mask values */
#define CL_AVC_ME_INTRA_LUMA_PARTITION_MASK_16x16_INTEL     0x6
#define CL_AVC_ME_INTRA_LUMA_PARTITION_MASK_8x8_INTEL       0x5
#define CL_AVC_ME_INTRA_LUMA_PARTITION_MASK_4x4_INTEL       0x3

/* Intra neighbor availability mask values */
#define CL_AVC_ME_INTRA_NEIGHBOR_LEFT_MASK_ENABLE_INTEL     0x60
#define CL_AVC_ME_INTRA_NEIGHBOR_UPPER_MASK_ENABLE_INTEL    0x10
#define CL_AVC_ME_INTRA_NEIGHBOR_UPPER_RIGHT_MASK_ENABLE_INTEL 0x8
#define CL_AVC_ME_INTRA_NEIGHBOR_UPPER_LEFT_MASK_ENABLE_INTEL 0x4

/* Luma intra modes */
#define CL_AVC_ME_LUMA_PREDICTOR_MODE_VERTICAL_INTEL        0x0
#define CL_AVC_ME_LUMA_PREDICTOR_MODE_HORIZONTAL_INTEL      0x1
#define CL_AVC_ME_LUMA_PREDICTOR_MODE_DC_INTEL              0x2
#define CL_AVC_ME_LUMA_PREDICTOR_MODE_DIAGONAL_DOWN_LEFT_INTEL 0x3
#define CL_AVC_ME_LUMA_PREDICTOR_MODE_DIAGONAL_DOWN_RIGHT_INTEL 0x4
#define CL_AVC_ME_LUMA_PREDICTOR_MODE_PLANE_INTEL           0x4
#define CL_AVC_ME_LUMA_PREDICTOR_MODE_VERTICAL_RIGHT_INTEL  0x5
#define CL_AVC_ME_LUMA_PREDICTOR_MODE_HORIZONTAL_DOWN_INTEL 0x6
#define CL_AVC_ME_LUMA_PREDICTOR_MODE_VERTICAL_LEFT_INTEL   0x7
#define CL_AVC_ME_LUMA_PREDICTOR_MODE_HORIZONTAL_UP_INTEL   0x8

/* Chroma intra modes */
#define CL_AVC_ME_CHROMA_PREDICTOR_MODE_DC_INTEL            0x0
#define CL_AVC_ME_CHROMA_PREDICTOR_MODE_HORIZONTAL_INTEL    0x1
#define CL_AVC_ME_CHROMA_PREDICTOR_MODE_VERTICAL_INTEL      0x2
#define CL_AVC_ME_CHROMA_PREDICTOR_MODE_PLANE_INTEL         0x3

/* Reference image select values */
#define CL_AVC_ME_FRAME_FORWARD_INTEL                       0x1
#define CL_AVC_ME_FRAME_BACKWARD_INTEL                      0x2
#define CL_AVC_ME_FRAME_DUAL_INTEL                          0x3

/* Slice type values */
#define CL_AVC_ME_SLICE_TYPE_PRED_INTEL                     0x0
#define CL_AVC_ME_SLICE_TYPE_BPRED_INTEL                    0x1
#define CL_AVC_ME_SLICE_TYPE_INTRA_INTEL                    0x2

/* Interlaced image field polarity values */
#define CL_AVC_ME_INTERLACED_SCAN_TOP_FIELD_INTEL           0x0
#define CL_AVC_ME_INTERLACED_SCAN_BOTTOM_FIELD_INTEL        0x1

/***************************************************************
* cl_intel_driver_diagnostics
***************************************************************/
#define cl_intel_driver_diagnostics 1
#define CL_INTEL_DRIVER_DIAGNOSTICS "cl_intel_driver_diagnostics"

typedef cl_uint             cl_diagnostics_verbose_level;

/* cl_context_properties */
#define CL_CONTEXT_SHOW_DIAGNOSTICS_INTEL                   0x4106
#define CL_CONTEXT_DIAGNOSTICS_LEVEL_ALL_INTEL              0xff
#define CL_CONTEXT_DIAGNOSTICS_LEVEL_GOOD_INTEL             (1 << 0)
#define CL_CONTEXT_DIAGNOSTICS_LEVEL_BAD_INTEL              (1 << 1)
#define CL_CONTEXT_DIAGNOSTICS_LEVEL_NEUTRAL_INTEL          (1 << 2)

/***************************************************************
* cl_intel_egl_image_yuv
***************************************************************/
#define cl_intel_egl_image_yuv 1
#define CL_INTEL_EGL_IMAGE_YUV "cl_intel_egl_image_yuv"

/* cl_egl_image_properties_khr */
#define CL_EGL_YUV_PLANE_INTEL                              0x4107

/***************************************************************
* cl_intel_mem_channel_property
***************************************************************/
#define cl_intel_mem_channel_property 1
#define CL_INTEL_MEM_CHANNEL_PROPERTY "cl_intel_mem_channel_property"

/* cl_mem_properties_intel */
#define CL_MEM_CHANNEL_INTEL                                0x4213

/***************************************************************
* cl_intel_mem_force_host_memory
***************************************************************/
#define cl_intel_mem_force_host_memory 1
#define CL_INTEL_MEM_FORCE_HOST_MEMORY "cl_intel_mem_force_host_memory"

/* cl_mem_flags */
#define CL_MEM_FORCE_HOST_MEMORY_INTEL                      (1 << 20)

/***************************************************************
* cl_intel_motion_estimation
***************************************************************/
#define cl_intel_motion_estimation 1
#define CL_INTEL_MOTION_ESTIMATION "cl_intel_motion_estimation"

typedef struct _cl_motion_estimation_desc_intel {
    cl_uint mb_block_type;
    cl_uint subpixel_mode;
    cl_uint sad_adjust_mode;
    cl_uint search_path_type;
} cl_motion_estimation_desc_intel;

/* cl_accelerator_type_intel */
#define CL_ACCELERATOR_TYPE_MOTION_ESTIMATION_INTEL         0x0

/* cl_uint mb_block_type */
#define CL_ME_MB_TYPE_16x16_INTEL                           0x0
#define CL_ME_MB_TYPE_8x8_INTEL                             0x1
#define CL_ME_MB_TYPE_4x4_INTEL                             0x2

/* cl_uint subpixel_mode */
#define CL_ME_SUBPIXEL_MODE_INTEGER_INTEL                   0x0
#define CL_ME_SUBPIXEL_MODE_HPEL_INTEL                      0x1
#define CL_ME_SUBPIXEL_MODE_QPEL_INTEL                      0x2

/* cl_uint sad_adjust_mode */
#define CL_ME_SAD_ADJUST_MODE_NONE_INTEL                    0x0
#define CL_ME_SAD_ADJUST_MODE_HAAR_INTEL                    0x1

/* cl_uint search_path_type */
#define CL_ME_SEARCH_PATH_RADIUS_2_2_INTEL                  0x0
#define CL_ME_SEARCH_PATH_RADIUS_4_4_INTEL                  0x1
#define CL_ME_SEARCH_PATH_RADIUS_16_12_INTEL                0x5

/***************************************************************
* cl_intel_packed_yuv
***************************************************************/
#define cl_intel_packed_yuv 1
#define CL_INTEL_PACKED_YUV "cl_intel_packed_yuv"

/* cl_channel_order */
#define CL_YUYV_INTEL                                       0x4076
#define CL_UYVY_INTEL                                       0x4077
#define CL_YVYU_INTEL                                       0x4078
#define CL_VYUY_INTEL                                       0x4079

/***************************************************************
* cl_intel_planar_yuv
***************************************************************/
#define cl_intel_planar_yuv 1
#define CL_INTEL_PLANAR_YUV "cl_intel_planar_yuv"

/* cl_channel_order */
#define CL_NV12_INTEL                                       0x410E

/* cl_mem_flags */
#define CL_MEM_NO_ACCESS_INTEL                              (1 << 24)
#define CL_MEM_ACCESS_FLAGS_UNRESTRICTED_INTEL              (1 << 25)

/* cl_device_info */
#define CL_DEVICE_PLANAR_YUV_MAX_WIDTH_INTEL                0x417E
#define CL_DEVICE_PLANAR_YUV_MAX_HEIGHT_INTEL               0x417F

/***************************************************************
* cl_intel_required_subgroup_size
***************************************************************/
#define cl_intel_required_subgroup_size 1
#define CL_INTEL_REQUIRED_SUBGROUP_SIZE "cl_intel_required_subgroup_size"

/* cl_device_info */
#define CL_DEVICE_SUB_GROUP_SIZES_INTEL                     0x4108

/* cl_kernel_work_group_info */
#define CL_KERNEL_SPILL_MEM_SIZE_INTEL                      0x4109

/* cl_kernel_sub_group_info */
#define CL_KERNEL_COMPILE_SUB_GROUP_SIZE_INTEL              0x410A

/***************************************************************
* cl_intel_sharing_format_query
***************************************************************/
#define cl_intel_sharing_format_query 1
#define CL_INTEL_SHARING_FORMAT_QUERY "cl_intel_sharing_format_query"

/***************************************************************
* cl_intel_simultaneous_sharing
***************************************************************/
#define cl_intel_simultaneous_sharing 1
#define CL_INTEL_SIMULTANEOUS_SHARING "cl_intel_simultaneous_sharing"

/* cl_device_info */
#define CL_DEVICE_SIMULTANEOUS_INTEROPS_INTEL               0x4104
#define CL_DEVICE_NUM_SIMULTANEOUS_INTEROPS_INTEL           0x4105

/***************************************************************
* cl_intel_thread_local_exec
***************************************************************/
#define cl_intel_thread_local_exec 1
#define CL_INTEL_THREAD_LOCAL_EXEC "cl_intel_thread_local_exec"

/* cl_command_queue_properties - bitfield */
#define CL_QUEUE_THREAD_LOCAL_EXEC_ENABLE_INTEL             (1 << 31)

/***************************************************************
* cl_intel_unified_shared_memory
***************************************************************/
#define cl_intel_unified_shared_memory 1
#define CL_INTEL_UNIFIED_SHARED_MEMORY "cl_intel_unified_shared_memory"

typedef cl_bitfield         cl_device_unified_shared_memory_capabilities_intel;
/* type cl_mem_properties_intel */
typedef cl_bitfield         cl_mem_alloc_flags_intel;
typedef cl_uint             cl_mem_info_intel;
typedef cl_uint             cl_unified_shared_memory_type_intel;
typedef cl_uint             cl_mem_advice_intel;

/* cl_device_info */
#define CL_DEVICE_HOST_MEM_CAPABILITIES_INTEL               0x4190
#define CL_DEVICE_DEVICE_MEM_CAPABILITIES_INTEL             0x4191
#define CL_DEVICE_SINGLE_DEVICE_SHARED_MEM_CAPABILITIES_INTEL 0x4192
#define CL_DEVICE_CROSS_DEVICE_SHARED_MEM_CAPABILITIES_INTEL 0x4193
#define CL_DEVICE_SHARED_SYSTEM_MEM_CAPABILITIES_INTEL      0x4194

/* cl_unified_shared_memory_capabilities_intel - bitfield */
#define CL_UNIFIED_SHARED_MEMORY_ACCESS_INTEL               (1 << 0)
#define CL_UNIFIED_SHARED_MEMORY_ATOMIC_ACCESS_INTEL        (1 << 1)
#define CL_UNIFIED_SHARED_MEMORY_CONCURRENT_ACCESS_INTEL    (1 << 2)
#define CL_UNIFIED_SHARED_MEMORY_CONCURRENT_ATOMIC_ACCESS_INTEL (1 << 3)

/* cl_mem_properties_intel */
#define CL_MEM_ALLOC_FLAGS_INTEL                            0x4195

/* cl_mem_alloc_flags_intel - bitfield */
#define CL_MEM_ALLOC_WRITE_COMBINED_INTEL                   (1 << 0)

/* cl_mem_alloc_info_intel */
#define CL_MEM_ALLOC_TYPE_INTEL                             0x419A
#define CL_MEM_ALLOC_BASE_PTR_INTEL                         0x419B
#define CL_MEM_ALLOC_SIZE_INTEL                             0x419C
#define CL_MEM_ALLOC_DEVICE_INTEL                           0x419D

/* cl_unified_shared_memory_type_intel */
#define CL_MEM_TYPE_UNKNOWN_INTEL                           0x4196
#define CL_MEM_TYPE_HOST_INTEL                              0x4197
#define CL_MEM_TYPE_DEVICE_INTEL                            0x4198
#define CL_MEM_TYPE_SHARED_INTEL                            0x4199

/* cl_kernel_exec_info */
#define CL_KERNEL_EXEC_INFO_INDIRECT_HOST_ACCESS_INTEL      0x4200
#define CL_KERNEL_EXEC_INFO_INDIRECT_DEVICE_ACCESS_INTEL    0x4201
#define CL_KERNEL_EXEC_INFO_INDIRECT_SHARED_ACCESS_INTEL    0x4202
#define CL_KERNEL_EXEC_INFO_USM_PTRS_INTEL                  0x4203

/* cl_command_type */
#define CL_COMMAND_MEMFILL_INTEL                            0x4204
#define CL_COMMAND_MEMCPY_INTEL                             0x4205
#define CL_COMMAND_MIGRATEMEM_INTEL                         0x4206
#define CL_COMMAND_MEMADVISE_INTEL                          0x4207


extern CL_API_ENTRY void* CL_API_CALL
clHostMemAllocINTEL(
    cl_context context,
    const cl_mem_properties_intel* properties,
    size_t size,
    cl_uint alignment,
    cl_int* errcode_ret) ;

typedef void* (CL_API_CALL *
clHostMemAllocINTEL_fn)(
    cl_context context,
    const cl_mem_properties_intel* properties,
    size_t size,
    cl_uint alignment,
    cl_int* errcode_ret) ;

extern CL_API_ENTRY void* CL_API_CALL
clDeviceMemAllocINTEL(
    cl_context context,
    cl_device_id device,
    const cl_mem_properties_intel* properties,
    size_t size,
    cl_uint alignment,
    cl_int* errcode_ret) ;

typedef void* (CL_API_CALL *
clDeviceMemAllocINTEL_fn)(
    cl_context context,
    cl_device_id device,
    const cl_mem_properties_intel* properties,
    size_t size,
    cl_uint alignment,
    cl_int* errcode_ret) ;

extern CL_API_ENTRY void* CL_API_CALL
clSharedMemAllocINTEL(
    cl_context context,
    cl_device_id device,
    const cl_mem_properties_intel* properties,
    size_t size,
    cl_uint alignment,
    cl_int* errcode_ret) ;

typedef void* (CL_API_CALL *
clSharedMemAllocINTEL_fn)(
    cl_context context,
    cl_device_id device,
    const cl_mem_properties_intel* properties,
    size_t size,
    cl_uint alignment,
    cl_int* errcode_ret) ;

extern CL_API_ENTRY cl_int CL_API_CALL
clMemFreeINTEL(
    cl_context context,
    void* ptr) ;

typedef cl_int (CL_API_CALL *
clMemFreeINTEL_fn)(
    cl_context context,
    void* ptr) ;

extern CL_API_ENTRY cl_int CL_API_CALL
clMemBlockingFreeINTEL(
    cl_context context,
    void* ptr) ;

typedef cl_int (CL_API_CALL *
clMemBlockingFreeINTEL_fn)(
    cl_context context,
    void* ptr) ;

extern CL_API_ENTRY cl_int CL_API_CALL
clGetMemAllocInfoINTEL(
    cl_context context,
    const void* ptr,
    cl_mem_info_intel param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret) ;

typedef cl_int (CL_API_CALL *
clGetMemAllocInfoINTEL_fn)(
    cl_context context,
    const void* ptr,
    cl_mem_info_intel param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret) ;

extern CL_API_ENTRY cl_int CL_API_CALL
clSetKernelArgMemPointerINTEL(
    cl_kernel kernel,
    cl_uint arg_index,
    const void* arg_value) ;

typedef cl_int (CL_API_CALL *
clSetKernelArgMemPointerINTEL_fn)(
    cl_kernel kernel,
    cl_uint arg_index,
    const void* arg_value) ;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueMemsetINTEL(
    cl_command_queue command_queue,
    void* dst_ptr,
    cl_int value,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;

typedef cl_int (CL_API_CALL *
clEnqueueMemsetINTEL_fn)(
    cl_command_queue command_queue,
    void* dst_ptr,
    cl_int value,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueMemFillINTEL(
    cl_command_queue command_queue,
    void* dst_ptr,
    const void* pattern,
    size_t pattern_size,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;

typedef cl_int (CL_API_CALL *
clEnqueueMemFillINTEL_fn)(
    cl_command_queue command_queue,
    void* dst_ptr,
    const void* pattern,
    size_t pattern_size,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueMemcpyINTEL(
    cl_command_queue command_queue,
    cl_bool blocking,
    void* dst_ptr,
    const void* src_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;

typedef cl_int (CL_API_CALL *
clEnqueueMemcpyINTEL_fn)(
    cl_command_queue command_queue,
    cl_bool blocking,
    void* dst_ptr,
    const void* src_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueMemAdviseINTEL(
    cl_command_queue command_queue,
    const void* ptr,
    size_t size,
    cl_mem_advice_intel advice,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;

typedef cl_int (CL_API_CALL *
clEnqueueMemAdviseINTEL_fn)(
    cl_command_queue command_queue,
    const void* ptr,
    size_t size,
    cl_mem_advice_intel advice,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;

#if defined(CL_VERSION_1_2)
/* Requires OpenCL 1.2 for cl_mem_migration_flags: */

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueMigrateMemINTEL(
    cl_command_queue command_queue,
    const void* ptr,
    size_t size,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;

typedef cl_int (CL_API_CALL *
clEnqueueMigrateMemINTEL_fn)(
    cl_command_queue command_queue,
    const void* ptr,
    size_t size,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event) ;
#endif

/***************************************************************
* cl_nv_device_attribute_query
***************************************************************/
#define cl_nv_device_attribute_query 1
#define CL_NV_DEVICE_ATTRIBUTE_QUERY "cl_nv_device_attribute_query"

/* cl_device_info */
#define CL_DEVICE_COMPUTE_CAPABILITY_MAJOR_NV               0x4000
#define CL_DEVICE_COMPUTE_CAPABILITY_MINOR_NV               0x4001
#define CL_DEVICE_REGISTERS_PER_BLOCK_NV                    0x4002
#define CL_DEVICE_WARP_SIZE_NV                              0x4003
#define CL_DEVICE_GPU_OVERLAP_NV                            0x4004
#define CL_DEVICE_KERNEL_EXEC_TIMEOUT_NV                    0x4005
#define CL_DEVICE_INTEGRATED_MEMORY_NV                      0x4006

/***************************************************************
* cl_qcom_android_native_buffer_host_ptr
***************************************************************/
#define cl_qcom_android_native_buffer_host_ptr 1
#define CL_QCOM_ANDROID_NATIVE_BUFFER_HOST_PTR "cl_qcom_android_native_buffer_host_ptr"

typedef struct _cl_mem_ext_host_ptr {
    cl_uint allocation_type;
    cl_uint host_cache_policy;
} cl_mem_ext_host_ptr;
typedef struct _cl_mem_android_native_buffer_host_ptr {
    cl_mem_ext_host_ptr ext_host_ptr;
    void* anb_ptr;
} cl_mem_android_native_buffer_host_ptr;

/* cl_uint allocation_type */
#define CL_MEM_ANDROID_NATIVE_BUFFER_HOST_PTR_QCOM          0x40C6

/***************************************************************
* cl_qcom_ext_host_ptr
***************************************************************/
#define cl_qcom_ext_host_ptr 1
#define CL_QCOM_EXT_HOST_PTR "cl_qcom_ext_host_ptr"

typedef cl_uint             cl_image_pitch_info_qcom;
/* type cl_mem_ext_host_ptr */

/* cl_mem_flags */
#define CL_MEM_EXT_HOST_PTR_QCOM                            (1 << 29)

/* cl_device_info */
#define CL_DEVICE_EXT_MEM_PADDING_IN_BYTES_QCOM             0x40A0
#define CL_DEVICE_PAGE_SIZE_QCOM                            0x40A1

/* cl_image_pitch_info_qcom */
#define CL_IMAGE_ROW_ALIGNMENT_QCOM                         0x40A2
#define CL_IMAGE_SLICE_ALIGNMENT_QCOM                       0x40A3

/* cl_uint host_cache_policy */
#define CL_MEM_HOST_UNCACHED_QCOM                           0x40A4
#define CL_MEM_HOST_WRITEBACK_QCOM                          0x40A5
#define CL_MEM_HOST_WRITETHROUGH_QCOM                       0x40A6
#define CL_MEM_HOST_WRITE_COMBINING_QCOM                    0x40A7


extern CL_API_ENTRY cl_int CL_API_CALL
clGetDeviceImageInfoQCOM(
    cl_device_id device,
    size_t image_width,
    size_t image_height,
    const cl_image_format* image_format,
    cl_image_pitch_info_qcom param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret) ;

typedef cl_int (CL_API_CALL *
clGetDeviceImageInfoQCOM_fn)(
    cl_device_id device,
    size_t image_width,
    size_t image_height,
    const cl_image_format* image_format,
    cl_image_pitch_info_qcom param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret) ;

/***************************************************************
* cl_qcom_ext_host_ptr_iocoherent
***************************************************************/
#define cl_qcom_ext_host_ptr_iocoherent 1
#define CL_QCOM_EXT_HOST_PTR_IOCOHERENT "cl_qcom_ext_host_ptr_iocoherent"

/* cl_uint host_cache_policy */
#define CL_MEM_HOST_IOCOHERENT_QCOM                         0x40A9

/***************************************************************
* cl_qcom_ion_host_ptr
***************************************************************/
#define cl_qcom_ion_host_ptr 1
#define CL_QCOM_ION_HOST_PTR "cl_qcom_ion_host_ptr"

/* type cl_mem_ext_host_ptr */
typedef struct _cl_mem_ion_host_ptr {
    cl_mem_ext_host_ptr ext_host_ptr;
    int ion_filedesc;
    void* ion_hostptr;
} cl_mem_ion_host_ptr;

/* cl_uint allocation_type */
#define CL_MEM_ION_HOST_PTR_QCOM                            0x40A8

/***************************************************************
* cl_intel_sharing_format_query
***************************************************************/
#define cl_intel_sharing_format_query 1

#ifdef __cplusplus
}
#endif

#endif /* OPENCL_CL_EXT_H_ */
