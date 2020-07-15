// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*-
// vim: ts=8 sw=2 smarttab ft=cpp

#ifndef CEPH_RGW_PERIOD_PULLER_H
#define CEPH_RGW_PERIOD_PULLER_H

#include "rgw_period_history.h"
#include "include/common_fwd.h"

class RGWPeriod;

class RGWPeriodPuller : public RGWPeriodHistory::Puller {
  CephContext *cct;

  struct {
    RGWSI_Zone *zone;
    RGWSI_SysObj *sysobj;
  } svc;

 public:
  explicit RGWPeriodPuller(RGWSI_Zone *zone_svc, RGWSI_SysObj *sysobj_svc);

  int pull(const std::string& period_id, RGWPeriod& period) override;
};

#endif // CEPH_RGW_PERIOD_PULLER_H
