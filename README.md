# Pyrocketry

Pyrocketry is a Python library written in C that contains important mathematical and physical rocket equations.

## Instlation

```shell
$ python3 setup.py install
```

## Usage

### Import library

```python
import pyrocketry as pr
```

## Equations

### Tsiolkovsky rocket equation

![equation](https://wikimedia.org/api/rest_v1/media/math/render/svg/f4f0e5fa252e0c5f23c387f1bfdf6784017907dc)

Pyrocketry solution.

```python
help(pr.Tre)

    Tsiolkovsky rocket equation.

    Args:
        Isp (float): The specific impulse in dimension of time.
        Mo (float): The initial total mass, including propellant, a.k.a. wet mass.
        Mf (float): The final total mass without propellant, a.k.a. dry mass.
        g (:obj:`float`, optional): Standard gravity. Defaults to 9.80665.

    Returns:
        V (float): The maximum change of velocity of the vehicle.
```

### Suicide burn calculation

```python
help(pr.suicide_burn_height)

    Suicide burn height calculation.

    Args:
        Vz (float): Vertical velocity.
        Fth (float): Force from thrust.
        Mship (float) Total mass of a vehicle.
        g (:obj:`float`, optional): Standard gravity. Defaults to 9.80665.

    Returns:
        H (float): Height for suicide burn start.
```
