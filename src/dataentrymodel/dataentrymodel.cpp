#include "dataentrymodel.h"

DataEntryModel::DataEntryModel(QObject *parent) :QAbstractListModel(parent)
{
    m_data = QColor::colorNames();
}

DataEntryModel::~DataEntryModel()
{}

int DataEntryModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.count();
}
QVariant DataEntryModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    if(row < 0 || row >=m_data.count()){
        return QVariant();
    }

    switch(role){
    case Qt::DisplayRole:
        return m_data.value(row);
    }
    return QVariant();
}
