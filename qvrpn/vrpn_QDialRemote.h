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
#ifndef INCLUDED_vrpn_QDialRemote_h_GUID_fd8bb49a_d415_4d43_8466_f64226e8934f
#define INCLUDED_vrpn_QDialRemote_h_GUID_fd8bb49a_d415_4d43_8466_f64226e8934f

// Internal Includes
// - none

// Library/third-party includes
#include <QObject>
#include <QString>
#include <QSharedPointer>

// Standard includes
// - none

class vrpn_Dial_Remote;
class vrpn_Connection;

/// A Qt-enabled wrapper object for VRPN Dial remotes.
class vrpn_QDialRemote : public QObject {
		Q_OBJECT
	public:
		vrpn_QDialRemote(QString const& name, vrpn_Connection * c = NULL, QObject * parent = NULL);
		~vrpn_QDialRemote();

	signals:
		void dialChanged(int id, double change);

	public slots:
		void mainloop();

	private:
		friend class vrpn_QDialRemote_impl;
		void _handleDial(int id, double change);
		QSharedPointer<vrpn_Dial_Remote> _contained;
};
#endif // INCLUDED_vrpn_QDialRemote_h_GUID_fd8bb49a_d415_4d43_8466_f64226e8934f
