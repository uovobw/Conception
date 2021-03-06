#pragma once
#ifndef __PointerMapping_H__
#define __PointerMapping_H__

class PointerMapping
	: public InputHandler
{
public:
	PointerMapping(Pointer & Owner, bool IsPure);
	~PointerMapping();
	//PointerMapping(const PointerMapping &) = default;
	PointerMapping & operator = (const PointerMapping &);

	void AddMapping(GestureRecognizer & GestureRecognizer);
	void DoneAdding();
	void RemoveMapping(GestureRecognizer & GestureRecognizer);
	void RemoveAllMappings();

	bool ContainsMapping(const GestureRecognizer * GestureRecognizer) const;

	void ProcessEvent(InputEvent & InputEvent) override;

	void ProcessTimePassed(const double TimePassed) override;

	void RequestPointerCapture(GestureRecognizer * Requester);
	void RequestPointerRelease(GestureRecognizer * Requester);

	GestureRecognizer * GetCapturer() const;
	GestureRecognizer * GetHoverer() const;

	const std::vector<GestureRecognizer *> & GetEntries() const;

	//void RemoveHoverPointer(Pointer * Pointer);

private:
	void ChangeCapturer(GestureRecognizer * Capturer);

	//GestureRecognizer *		m_Hoverer;
	GestureRecognizer *		m_Capturer;

	// There is duplication of information between m_Entries and GetConnected(), but m_Entries has additional information (order of elements)
	// that GetConnected() doesn't, so removing m_Entries outright won't work (perhaps I can change MutuallyConnectable to use std::vector instead of set?)
	std::vector<GestureRecognizer *>		m_Entries;

	bool m_IsPureTEST;		// If true, MutuallyConnectable stuff is skipped, only this instance contents are updated

	Pointer &				m_Owner;

	// DEBUG: For info printing
	friend class DebugOverlayWidget;
};

#endif // __PointerMapping_H__
