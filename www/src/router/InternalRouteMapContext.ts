import React, { createContext } from "react";
import { InternalEntryPoint } from "./InternalEntryPoint";

export type InternalRoute = {
  path: string;
  entrypoint: InternalEntryPoint,
}

export type InternalRouteMap = {
  [path: string]: InternalRoute;
}

export const defaultInternalRouteMap = {
};

export const InternalRouteMapContext = React.createContext<InternalRouteMap>(defaultInternalRouteMap);