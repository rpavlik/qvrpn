/** @file
	@brief Header

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

#pragma once
#ifndef INCLUDED_vrpn_QTrackerRemote_h_GUID_14e52650_3426_4f00_8bf7_d42f0096994b
#define INCLUDED_vrpn_QTrackerRemote_h_GUID_14e52650_3426_4f00_8bf7_d42f0096994b

// Internal Includes
// - none

// Library/third-party includes
#include <QObject>
#include <QString>
#include <QSharedPointer>
#include <qt4/QtGui/QQuaternion>
#include <qt4/QtGui/QVector3D>

// Standard includes
// - none

class vrpn_Tracker_Remote;
class vrpn_Connection;

/// A Qt-enabled wrapper object for VRPN Tracker remotes.
class vrpn_QTrackerRemote : public QObject {
		Q_OBJECT
	public:
		vrpn_QTrackerRemote(QString const& name, vrpn_Connection * c = NULL, QObject * parent = NULL);
		~vrpn_QTrackerRemote();

	signals:
		void poseReport(int sensor, QVector3D position, QQuaternion orientation);
	public slots:
		void mainloop();
	private:
		friend class vrpn_QTrackerRemote_impl;
		void _handleTracker(int sensor, QVector3D position, QQuaternion orientation);
		QSharedPointer<vrpn_Tracker_Remote> _contained;
};

#endif // INCLUDED_vrpn_QTrackerRemote_h_GUID_14e52650_3426_4f00_8bf7_d42f0096994b
