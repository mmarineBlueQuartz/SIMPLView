/* ============================================================================
 * Copyright (c) 2012 Michael A. Jackson (BlueQuartz Software)
 * Copyright (c) 2012 Dr. Michael A. Groeber (US Air Force Research Laboratories)
 * All rights reserved.
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
 * Neither the name of Michael A. Groeber, Michael A. Jackson, the US Air Force,
 * BlueQuartz Software nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior written
 * permission.
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
 *  This code was written under United States Air Force Contract number
 *                           FA8650-10-D-5210
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#ifndef _DataContainerArrayProxy_H_
#define _DataContainerArrayProxy_H_



#include <QtCore/QMetaType>
#include <QtCore/QString>
#include <QtCore/QList>
#include <QtCore/QStringList>
#include <QtCore/QTextStream>
#include <QtCore/QJsonObject>

#include "DREAM3DLib/DREAM3DLib.h"
#include "DREAM3DLib/DataContainers/DataContainerProxy.h"
#include "DREAM3DLib/DataContainers/DataArrayPath.h"

class DataContainerArray;

/**
 * @brief DataContainerArrayProxy
 */
class DREAM3DLib_EXPORT DataContainerArrayProxy
{
  public:
    /**
     * @brief DataContainerArrayProxy
     */
    DataContainerArrayProxy();

    /**
     * @brief DataContainerArrayProxy
     * @param dca
     */
    explicit DataContainerArrayProxy(DataContainerArray* dca);

    /**
     * @brief DataContainerArrayProxy
     * @param rhs
     */
    DataContainerArrayProxy(const DataContainerArrayProxy& rhs);

    /**
     * @brief ~DataContainerArrayProxy
     */
    virtual ~DataContainerArrayProxy();

    /**
     * @brief MergeProxies
     * @param fileProxy
     * @param cacheProxy
     * @return
     */
    static DataContainerArrayProxy MergeProxies(DataContainerArrayProxy fileProxy, DataContainerArrayProxy cacheProxy);

    /**
     * @brief operator =
     * @param rhs
     */
    void operator=(const DataContainerArrayProxy& rhs);

    /**
     * @brief flattenHeirarchy
     * @param dcFlag
     * @param amFlag
     * @param daFlag
     * @return
     */
    QStringList flattenHeirarchy(Qt::CheckState dcFlag = Qt::Checked, Qt::CheckState amFlag = Qt::Checked, Qt::CheckState daFlag = Qt::Checked);

    /**
     * @brief Print the Heirarchy and attributes of the Proxy
     * @param out
     */
    void print(const QString header = QString(""));

    /**
     * @brief setAllFlags
     * @param state
     */
    void setAllFlags(Qt::CheckState state);

    /**
     * @brief reverseFlags
     */
    void reverseFlags();

    /**
     * @brief serialize
     * @return
     */
    QStringList serialize();

    /**
     * @brief Does this contain a DataContainer for the given name
     * @param name
     * @return
     */
    bool contains(const QString& name);

    /**
     * @brief getDataContainerProxy This will return the DataContainerProxy associated
     * with the name given. If a DataContainerProxy with the given name does NOT
     * exist in the DataContainerArrayProxy then a new one will be inserted. If this
     * is NOT what you want, then use the @see contains(QString) function first
     * to make sure the DataContainerArray has the DataContainer that you are
     * looking for.
     * @param name The name of the DataContainer.
     * @return
     */
    DataContainerProxy& getDataContainerProxy(const QString& name);

    /**
    * @brief Writes the contents of the proxy to the json object 'json'
    * @param json
    * @return
    */
    void writeJson(QJsonObject &json);

    /**
    * @brief Reads the contents of the the json object 'json' into the proxy
    * @param json
    * @return
    */
    bool readJson(QJsonObject &json);

    //----- Our variables, publicly available
    QMap<QString, DataContainerProxy>  dataContainers;

    private:

      /**
      * @brief Writes the contents of the map to a json array
      * @param map
      * @return QJsonArray
      */
      QJsonArray writeMap(QMap<QString, DataContainerProxy> map);

      /**
      * @brief Reads the contents of the json array to a QMap
      * @param jsonArray
      * @return
      */
      QMap<QString, DataContainerProxy> readMap(QJsonArray jsonArray);
};

Q_DECLARE_METATYPE(DataContainerArrayProxy)

#endif /* _DataContainerArrayProxy_H_ */

