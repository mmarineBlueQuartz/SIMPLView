/* ============================================================================
* Copyright (c) 2009-2015 BlueQuartz Software, LLC
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright notice, this
* list of conditions and the following disclaimer in the documentation and/or
* other materials provided with the distribution.
*
* Neither the name of BlueQuartz Software, the US Air Force, nor the names of its
* contributors may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
* USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* The code contained herein was partially funded by the followig contracts:
*    United States Air Force Prime Contract FA8650-07-D-5800
*    United States Air Force Prime Contract FA8650-10-D-5210
*    United States Prime Contract Navy N00173-07-C-2068
*
* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


#ifndef _YSChoiAbaqusReader_H_
#define _YSChoiAbaqusReader_H_

#include <string.h> // needed for the ::memcpy function below
#include <QtCore/QString>


#include "DREAM3DLib/DREAM3DLib.h"
#include "DREAM3DLib/Common/Constants.h"
#include "DREAM3DLib/Common/DREAM3DSetGetMacros.h"
#include "DREAM3DLib/CoreFilters/FileReader.h"
#include "DREAM3DLib/DataArrays/DataArray.hpp"


class  YSChoiAbaqusReader : public FileReader
{
    Q_OBJECT /* Need this for Qt's signals and slots mechanism to work */
  public:
    DREAM3D_SHARED_POINTERS(YSChoiAbaqusReader)
    DREAM3D_STATIC_NEW_MACRO(YSChoiAbaqusReader)
    DREAM3D_TYPE_MACRO_SUPER(YSChoiAbaqusReader, FileReader)

    virtual ~YSChoiAbaqusReader();

    DREAM3D_FILTER_PARAMETER(QString, DataContainerName)
    Q_PROPERTY(QString DataContainerName READ getDataContainerName WRITE setDataContainerName)

    DREAM3D_FILTER_PARAMETER(QString, CellEnsembleAttributeMatrixName)
    Q_PROPERTY(QString CellEnsembleAttributeMatrixName READ getCellEnsembleAttributeMatrixName WRITE setCellEnsembleAttributeMatrixName)

    DREAM3D_FILTER_PARAMETER(QString, CellFeatureAttributeMatrixName)
    Q_PROPERTY(QString CellFeatureAttributeMatrixName READ getCellFeatureAttributeMatrixName WRITE setCellFeatureAttributeMatrixName)

    DREAM3D_FILTER_PARAMETER(QString, CellAttributeMatrixName)
    Q_PROPERTY(QString CellAttributeMatrixName READ getCellAttributeMatrixName WRITE setCellAttributeMatrixName)

    DREAM3D_FILTER_PARAMETER(QString, InputFile)
    Q_PROPERTY(QString InputFile READ getInputFile WRITE setInputFile)

    DREAM3D_FILTER_PARAMETER(QString, InputFeatureInfoFile)
    Q_PROPERTY(QString InputFeatureInfoFile READ getInputFeatureInfoFile WRITE setInputFeatureInfoFile)

    DREAM3D_FILTER_PARAMETER(QString, CellEulerAnglesArrayName)
    Q_PROPERTY(QString CellEulerAnglesArrayName READ getCellEulerAnglesArrayName WRITE setCellEulerAnglesArrayName)

    DREAM3D_FILTER_PARAMETER(QString, QuatsArrayName)
    Q_PROPERTY(QString QuatsArrayName READ getQuatsArrayName WRITE setQuatsArrayName)

    DREAM3D_FILTER_PARAMETER(QString, AvgQuatsArrayName)
    Q_PROPERTY(QString AvgQuatsArrayName READ getAvgQuatsArrayName WRITE setAvgQuatsArrayName)

    DREAM3D_FILTER_PARAMETER(QString, CellPhasesArrayName)
    Q_PROPERTY(QString CellPhasesArrayName READ getCellPhasesArrayName WRITE setCellPhasesArrayName)

    DREAM3D_FILTER_PARAMETER(QString, SurfaceFeaturesArrayName)
    Q_PROPERTY(QString SurfaceFeaturesArrayName READ getSurfaceFeaturesArrayName WRITE setSurfaceFeaturesArrayName)

    DREAM3D_FILTER_PARAMETER(QString, FeatureIdsArrayName)
    Q_PROPERTY(QString FeatureIdsArrayName READ getFeatureIdsArrayName WRITE setFeatureIdsArrayName)

    DREAM3D_FILTER_PARAMETER(QString, CrystalStructuresArrayName)
    Q_PROPERTY(QString CrystalStructuresArrayName READ getCrystalStructuresArrayName WRITE setCrystalStructuresArrayName)

    /**
     * @brief getCompiledLibraryName Reimplemented from @see AbstractFilter class
     */
    virtual const QString getCompiledLibraryName();

    /**
     * @brief newFilterInstance Reimplemented from @see AbstractFilter class
     */
    virtual AbstractFilter::Pointer newFilterInstance(bool copyFilterParameters);

    /**
     * @brief getGroupName Reimplemented from @see AbstractFilter class
     */
    virtual const QString getGroupName();

    /**
     * @brief getSubGroupName Reimplemented from @see AbstractFilter class
     */
    virtual const QString getSubGroupName();

    /**
     * @brief getHumanLabel Reimplemented from @see AbstractFilter class
     */
    virtual const QString getHumanLabel();

    /**
     * @brief setupFilterParameters Reimplemented from @see AbstractFilter class
     */
    virtual void setupFilterParameters();

    /**
     * @brief writeFilterParameters Reimplemented from @see AbstractFilter class
     */
    virtual int writeFilterParameters(AbstractFilterParametersWriter* writer, int index);

    /**
     * @brief readFilterParameters Reimplemented from @see AbstractFilter class
     */
    virtual void readFilterParameters(AbstractFilterParametersReader* reader, int index);

   /**
    * @brief execute Reimplemented from @see AbstractFilter class
    */
    virtual void execute();

    /**
    * @brief preflight Reimplemented from @see AbstractFilter class
    */
    virtual void preflight();

  protected:
    YSChoiAbaqusReader();

    /**
     * @brief readFile Reimplemented from @see FileReader class
     */
    void dataCheck();

  private:
    DEFINE_CREATED_DATAARRAY_VARIABLE(int32_t, FeatureIds)
    DEFINE_CREATED_DATAARRAY_VARIABLE(int32_t, CellPhases)
    DEFINE_CREATED_DATAARRAY_VARIABLE(bool, SurfaceFeatures)
    DEFINE_CREATED_DATAARRAY_VARIABLE(float, Quats)
    DEFINE_CREATED_DATAARRAY_VARIABLE(float, AvgQuats)
    DEFINE_CREATED_DATAARRAY_VARIABLE(float, CellEulerAngles)
    DEFINE_CREATED_DATAARRAY_VARIABLE(unsigned int, CrystalStructures)

    void updateCellInstancePointers();

    void updateFeatureInstancePointers();

    void updateEnsembleInstancePointers();

    YSChoiAbaqusReader(const YSChoiAbaqusReader&); // Copy Constructor Not Implemented
    void operator=(const YSChoiAbaqusReader&); // Operator '=' Not Implemented
};

#endif /* YSChoiAbaqusReader_H_ */
