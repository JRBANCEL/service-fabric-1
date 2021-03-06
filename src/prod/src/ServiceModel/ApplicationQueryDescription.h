// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once

namespace ServiceModel
{
    class ApplicationQueryDescription
    {
        DENY_COPY(ApplicationQueryDescription)

    public:
        ApplicationQueryDescription();
        ~ApplicationQueryDescription() = default;

        Common::ErrorCode FromPublicApi(FABRIC_APPLICATION_QUERY_DESCRIPTION const & appQueryDesc);

        void GetQueryArgumentMap(__out QueryArgumentMap & argMap) const;
        Common::ErrorCode GetDescriptionFromQueryArgumentMap(QueryArgumentMap const & queryArgs);

        __declspec(property(get=get_ApplicationNameFilter, put = set_ApplicationNameFilter)) Common::NamingUri const & ApplicationNameFilter;
        __declspec(property(get=get_ApplicationTypeNameFilter, put = set_ApplicationTypeNameFilter)) std::wstring const & ApplicationTypeNameFilter;
        __declspec(property(get=get_ApplicationDefinitionKindFilter, put = set_ApplicationDefinitionKindFilter)) DWORD const ApplicationDefinitionKindFilter;
        __declspec(property(get=get_ExcludeApplicationParameter, put = set_ExcludeApplicationParameter)) bool ExcludeApplicationParameters;
        __declspec(property(get = get_QueryPagingDescriptionUPtr, put = set_QueryPagingDescriptionUPtr)) std::unique_ptr<QueryPagingDescription> const & QueryPagingDescriptionUPtr;

        // Get
        Common::NamingUri const & get_ApplicationNameFilter() const { return applicationNameFilter_; }
        std::wstring const & get_ApplicationTypeNameFilter() const { return applicationTypeNameFilter_; }
        DWORD const get_ApplicationDefinitionKindFilter() const { return applicationDefinitionKindFilter_; }
        bool get_ExcludeApplicationParameter() const { return excludeApplicationParameters_; }
        std::unique_ptr<QueryPagingDescription> const & get_QueryPagingDescriptionUPtr() const { return queryPagingDescriptionUPtr_; }

        // Set
        void set_ExcludeApplicationParameter(bool const value) { excludeApplicationParameters_ = value; }
        void set_ApplicationTypeNameFilter(std::wstring && value) { applicationTypeNameFilter_ = move(value); }
        void set_ApplicationNameFilter(Common::NamingUri && value) { applicationNameFilter_ = move(value); }
        void set_ApplicationDefinitionKindFilter(DWORD const value) { applicationDefinitionKindFilter_ = value; }
        void set_QueryPagingDescriptionUPtr(std::unique_ptr<QueryPagingDescription> && queryPagingDescription) { queryPagingDescriptionUPtr_ = std::move(queryPagingDescription); }

        bool IsExclusiveFilterHelper(bool const isValid, bool & hasFilterSet);
        void MovePagingDescription(__out unique_ptr<QueryPagingDescription> & pagingDescription) { pagingDescription = std::move(queryPagingDescriptionUPtr_); }
        std::wstring GetApplicationNameString() const;

    private:
        Common::NamingUri applicationNameFilter_;
        std::wstring applicationTypeNameFilter_;
        DWORD applicationDefinitionKindFilter_;
        bool excludeApplicationParameters_;
        std::unique_ptr<QueryPagingDescription> queryPagingDescriptionUPtr_;
    };
}
