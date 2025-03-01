#ifndef _INVEST_CONSUMER_H_
#define _INVEST_CONSUMER_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*
 * LEGAL NOTICE
 * This computer software was prepared by Battelle Memorial Institute,
 * hereinafter the Contractor, under Contract No. DE-AC05-76RL0 1830
 * with the Department of Energy (DOE). NEITHER THE GOVERNMENT NOR THE
 * CONTRACTOR MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY
 * LIABILITY FOR THE USE OF THIS SOFTWARE. This notice including this
 * sentence must appear on any copies of this computer software.
 * 
 * EXPORT CONTROL
 * User agrees that the Software will not be shipped, transferred or
 * exported into any country or used in any manner prohibited by the
 * United States Export Administration Act or any other applicable
 * export laws, restrictions or regulations (collectively the "Export Laws").
 * Export of the Software may require some form of license or other
 * authority from the U.S. Government, and failure to obtain such
 * export control license may result in criminal liability under
 * U.S. laws. In addition, if the Software is identified as export controlled
 * items under the Export Laws, User represents and warrants that User
 * is not a citizen, or otherwise located within, an embargoed nation
 * (including without limitation Iran, Syria, Sudan, Cuba, and North Korea)
 *     and that User is not otherwise prohibited
 * under the Export Laws from receiving the Software.
 * 
 * Copyright 2011 Battelle Memorial Institute.  All Rights Reserved.
 * Distributed as open-source under the terms of the Educational Community 
 * License version 2.0 (ECL 2.0). http://www.opensource.org/licenses/ecl2.php
 * 
 * For further details, see: http://www.globalchange.umd.edu/models/gcam/
 * 
 */


/*! 
* \file invest_consumer.h
* \ingroup Objects
* \brief InvestConsumer class header file.
*
*  Detailed description.
*
* \author Pralit Patel
* \author Sonny Kim
*/

#include <string>
#include <xercesc/dom/DOMNode.hpp>

#include "consumers/include/consumer.h"

class NationalAccount;
class Demographic;
class Tabs;
class IVisitor;

/*!
 * \brief A consumer representing the consumption caused by investment.
 */
class InvestConsumer : public Consumer
{
    friend class SocialAccountingMatrix;
    friend class DemandComponentsTable;
    friend class SectorReport;
    friend class SGMGenTable;
    friend class XMLDBOutputter;
    friend class CalcCapitalGoodPriceVisitor;
public:
	InvestConsumer();
	virtual InvestConsumer* clone() const;

	void copyParam( const BaseTechnology* baseTech,
                    const int aPeriod );

	void copyParamsInto( InvestConsumer& investConsumerIn,
                         const int aPeriod ) const;
    
    virtual void completeInit( const std::string& aRegionName,
                               const std::string& aSectorName,
                               const std::string& aSubsectorName );
    
    virtual void initCalc( const MoreSectorInfo* aMoreSectorInfo,
                           const std::string& aRegionName, 
                           const std::string& aSectorName,
                           NationalAccount& nationalAccount, 
                           const Demographic* aDemographics,
                           const double aCapitalStock,
                           const int aPeriod );
    
    virtual void operate( NationalAccount& aNationalAccount, const Demographic* aDemographics, 
        const MoreSectorInfo* moreSectorInfo, const std::string& aRegionName, 
        const std::string& aSectorName, const bool aIsNewVintageMode, const int aPeriod );
    
    void csvSGMOutputFile( std::ostream& aFile, const int period ) const;
    virtual void accept( IVisitor* aVisitor, const int aPeriod ) const;
    static const std::string& getXMLNameStatic();
protected:
    virtual bool isCoefBased() const { return false; }
    virtual const std::string& getXMLName() const;
    virtual bool XMLDerivedClassParse( const std::string& nodeName, const xercesc::DOMNode* curr );
    virtual void toInputXMLDerived( std::ostream& out, Tabs* tabs ) const;
    virtual void toDebugXMLDerived( const int period, std::ostream& out, Tabs* tabs ) const;

private:
    Value mCapitalGoodPrice; //!< Store the price of the capital good for reporting
    void allocateTransportationDemand( NationalAccount& aNationalAccount, 
        const std::string& aRegionName, int aPeriod );

    void allocateDistributionCost( NationalAccount& aNationalAccount, const std::string& aRegionName, 
        int aPeriod );

    void calcIncome( NationalAccount& aNationalAccount, const Demographic* aDemographics, 
        const std::string& aRegionName, int aPeriod );

    static const std::string XML_NAME; //!< node name for toXML methods
};

#endif // _TRADE_CONSUMER_H_

