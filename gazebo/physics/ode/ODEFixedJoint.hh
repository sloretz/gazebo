/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _GAZEBO_PHYSICS_ODE_ODEFIXEDJOINT_HH_
#define _GAZEBO_PHYSICS_ODE_ODEFIXEDJOINT_HH_

#include <ignition/math/Angle.hh>
#include <ignition/math/Vector3.hh>

#include "gazebo/physics/FixedJoint.hh"
#include "gazebo/physics/ode/ODEJoint.hh"
#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace physics
  {
    /// \brief A fixed joint.
    class GZ_PHYSICS_VISIBLE ODEFixedJoint : public FixedJoint<ODEJoint>
    {
      /// \brief Constructor
      /// \param[in] _worldID ODE id of the world.
      /// \param[in] _parent Parent of the Joint
      public: ODEFixedJoint(dWorldID _worldId, BasePtr _parent);

      /// \brief Destructor.
      public: virtual ~ODEFixedJoint();

      // Documentation inherited
      public: virtual void Load(sdf::ElementPtr _sdf);

      // Documentation inherited
      public: virtual ignition::math::Vector3d Anchor(
                  const unsigned int _index) const;

      // Documentation inherited
      public: virtual void SetAnchor(const unsigned int _index,
                 const ignition::math::Vector3d &_anchor);

      // Documentation inherited
      public: virtual ignition::math::Vector3d GlobalAxis(
                  const unsigned int _index) const;

      // Documentation inherited
      public: virtual void SetAxis(const unsigned int _index,
                  const ignition::math::Vector3d &_axis);

      // Documentation inherited
      public: virtual ignition::math::Angle AngleImpl(
                  const unsigned int _index) const;

      // Documentation inherited
      public: virtual void SetVelocity(const unsigned int _index,
                  const double _angle);

      // Documentation inherited
      public: virtual double Velocity(const unsigned int _index) const;

      // Documentation inherited
      public: virtual void Attach(LinkPtr _parent, LinkPtr _child);

      // Documentation inherited
      protected: virtual void SetForceImpl(const unsigned int _index,
                     const double _effort);
    };
  }
}
#endif