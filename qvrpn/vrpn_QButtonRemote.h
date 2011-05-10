/** @file
	@brief

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

#pragma once
#ifndef INCLUDED_vrpn_QButtonRemote_h_GUID_b716ec0b_7f9a_4b02_b1e8_00cccb488cb1
#define INCLUDED_vrpn_QButtonRemote_h_GUID_b716ec0b_7f9a_4b02_b1e8_00cccb488cb1

// Internal Includes
// - none

// Library/third-party includes
#include <QObject>
#include <QString>
#include <QSharedPointer>

// Standard includes
// - none

class vrpn_Button_Remote;
class vrpn_Connection;

/// A Qt-enabled wrapper object for VRPN Button remotes.
class vrpn_QButtonRemote : public QObject {
		Q_OBJECT
	public:
		vrpn_QButtonRemote(QString const& name, vrpn_Connection * c = NULL, QObject * parent = NULL);
		~vrpn_QButtonRemote();

	signals:
		void buttonChanged(int id, bool pressed);
		void buttonPressed(int id);
		void buttonReleased(int id);

	public slots:
		void mainloop();

	private:
		friend class vrpn_QButtonRemote_impl;
		void _handleButton(int id, bool pressed);
		QSharedPointer<vrpn_Button_Remote> _contained;
};
#endif // INCLUDED_vrpn_QButtonRemote_h_GUID_b716ec0b_7f9a_4b02_b1e8_00cccb488cb1
